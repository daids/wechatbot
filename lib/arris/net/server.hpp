#pragma once
#include <vector>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <nlohmann/json.hpp>
//#include <arris/mgr/handlemsg.hpp>
#include <arris/thread/wxthread.hpp>
#include <arris/wechat/msgdispatch.hpp>
#include <arris/mgr/mgrnew.hpp>

using namespace arris::objectmgr;
using namespace arris::util;
using namespace arris::thread;
using namespace arris::wechat;

using nlohmann::json;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

namespace arris {
    namespace net {

      
        const std::string g_http_para_name = "para";//for http body
        class arrisserver{
            using server = websocketpp::server<websocketpp::config::asio>;
            using message_ptr = server::message_ptr;

        public:
            arrisserver(unsigned int port):port_(port) {
                server_ = std::make_unique<server>();
                handlemsg_ = std::make_unique<mgrnew>();
                msgdispatch_ = std::make_unique<msgdispatch>();
                tinyjson_ = std::make_unique<tinyjson>();
                loop();//start loop
            }

            ~arrisserver() {
                stop();
            }


            void start(){
                try {
                    // Initialize ASIO
                    server_->init_asio();
                    server_->set_reuse_addr(true);

                    // Register our message handler
                    //server_->set_socket_init_handler(std::bind(&wsserver::init_send_msg_loop,this));
                    server_->set_open_handler(std::bind(&arrisserver::on_open, this, ::_1));
                    server_->set_message_handler(std::bind(&arrisserver::on_message, this, ::_1, ::_2));
                    server_->set_http_handler(std::bind(&arrisserver::on_http, this, ::_1));
                    server_->set_fail_handler(std::bind(&arrisserver::on_fail, this, ::_1));
                    server_->set_close_handler(std::bind(&arrisserver::on_close, this, ::_1));

                    server_->set_validate_handler(std::bind(&arrisserver::validate, this));
                    server_->listen(this->port_);
                    // Start the server accept loop
                    server_->start_accept();
                    set_timer();
                    server_->run();

                }
                catch (websocketpp::exception const& e) {
                    __OutputDebugString(TEXT("websocketpp exception:%s\n"),e.what());
                }
                catch (const std::exception& e) {
                    __OutputDebugString(TEXT("std exception:%s\n"), e.what());
                }
                catch (...) {
                    __OutputDebugString(TEXT("other exception!please review code!\n"));
                }
            }
            void stop(){
                server_->stop();
            }

        protected:
            void set_timer() {//15 second
                server_->set_timer(15000, std::bind(&arrisserver::on_timer, this));
            }
            void loop()
            {
                thread_pool.enqueue(std::bind(&arrisserver::send_msg_to_client, this));
            }
            void on_timer() {
                std::string heartbeat = tinyjson_->ret_msg(time2id(), kMsgOkStatus, "heart beat", static_cast<int>(MsgType::kHeartBeat));
                msgdispatch_->send_to_queue(heartbeat);
                set_timer();
            }
            
            void send_msg_to_client() {
                while (1) {

                    if (kMsgQueue.size() > 0) {
                        std::string queue_msg = kMsgQueue.front();
                        for (size_t i = 0; i < hdl_.size(); i++) {
                            websocketpp::connection_hdl hdl = hdl_[i];
                            this->server_->send(hdl, queue_msg, websocketpp::frame::opcode::text);
                        }
                        kMsgQueue.pop();
                    }
                    Sleep(1);//
                    continue;//sleep(1)+continue,½â¾öcpu 100%
                }
            }
            
            bool validate() {
                //sleep(6);
                return true;
            }

            void on_message(websocketpp::connection_hdl hdl, message_ptr msg) {

                try {
   
                    std::string result = handlemsg_->msg(msg->get_payload());
                    msgdispatch_->send_to_queue(result);
                }
                catch (websocketpp::exception const& e) {
                    __OutputDebugString(TEXT("websocket send exception:%s\n"), e.what());
                }
            }
            void on_fail(websocketpp::connection_hdl hdl)
            {
                server::connection_ptr con = this->server_->get_con_from_hdl(hdl);
                //__OutputDebugString(TEXT("websocket send exception:%s\n"), con->get_ec().message());

            }
            void on_close(websocketpp::connection_hdl hdl) {

                //free hdl
                hdl_.erase(std::remove_if(std::begin(hdl_), std::end(hdl_),
                    [&](const websocketpp::connection_hdl& a) {
                        if (a.lock() == hdl.lock()) return true;
                        return false;
                    }));
            }
            void on_http(websocketpp::connection_hdl hdl) {
                
                server::connection_ptr con = server_->get_con_from_hdl(hdl);
                
                con->append_header("Access-Control-Allow-Origin","*");
                
                websocketpp::http::parser::request rt = con->get_request();
                const std::string& uri = rt.get_uri();
                const std::string& strbody = rt.get_body();
                
                std::string result = handlemsg_->msg(g_http_para_name,strbody);
                con->set_body(result);
                con->set_status(websocketpp::http::status_code::ok);

            }
            void on_open(websocketpp::connection_hdl hdl) {
                hdl_.push_back(hdl);
            }
        private:
            std::vector<websocketpp::connection_hdl> hdl_;
            std::unique_ptr<server> server_;
            //std::unique_ptr<handlemsg> handlemsg_;
            std::unique_ptr<mgrnew> handlemsg_;
            std::unique_ptr<tinyjson> tinyjson_;
            std::unique_ptr<msgdispatch> msgdispatch_;
            unsigned int port_;


        };// class arrisserver        
    }//namespace net
}//namespace arris
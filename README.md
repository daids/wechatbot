## 微信公众号
```
希望老张有时间时能继续研究一下获取通讯录好友列表时能得到更多的数据，
现在只有wxid和昵称，能有备注名、头像地址、自己设置的微信号之类的
就更好了
```
### menu
```
《读读写写》  <a href="http://dwz.date/eCbz">点我进入......</a>
《养生和自律》<a href="http://dwz.date/eCb3">有些坑是可以避免的......</a> 
《微信机器人》<a href="https://pan.baidu.com/s/1JIvKepZL3ibmbqzPCuHYHw">提取码:djv4</a>
《机器人源码3.1.0.66》  <a href="https://pan.baidu.com/s/1FPu-ESbLJLUY6_Xm-Mq46g">提取码:fpzr</a>

```

## 功能
* 获取通讯录好友wxid,名字；
* 接收文本消息；
* 发送文本消息;
* 发送图片；
* 获取个人微信信息;
* 获取微信群id和群成员id;
* 获取群成员昵称，用如下代码，带wxid和roomid,单个获取
```
function get_chat_nick_p(wx_id,roomid)
{
  const j={
    id:getid(),
    type:CHATROOM_MEMBER_NICK,
    content:roomid,//chatroom id 23023281066@chatroom  17339716569@chatroom
    wxid:wx_id
  };
  const s= JSON.stringify(j);
  return s;
}
```
# 环境搭建
* 1、安装boost
* 2、vs2019 库目录设置：x:\xxxx\boost_1_74_0\stage\lib
* 3、vs2019 包含目录设置：x:\xxxx\boost_1_74_0
* 4、把lib和include设置进包含目录，见步骤3
# 说明
## 2021/01/03
* 非json判断
* 关闭websocket server并释放掉dll

## 2020/01/12
* 内存获取contact

## 2020/01/14
* 接受文本消息

## 2020/01/15
* 发送文本消息

## 2020/01/17
* 获取微信个人信息(wxid , 微信号 ，名字)

## 2020/01/18
* 获取群成员id和wxid(包含地址)

## 2020/01/19
* 修改cpu 100%的bug，改为定时1秒
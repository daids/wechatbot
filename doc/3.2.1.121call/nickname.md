68854D64     | 8D8D 2CF8FFFF     | lea ecx,dword ptr ss:[ebp-7D4]       | 【3.2.1.121】获取群成员昵称
68854D6A     | E8 91961F00       | call wechatwin.68A4E400              |
68854D6F     | 8D85 2CF8FFFF     | lea eax,dword ptr ss:[ebp-7D4]       |
68854D75     | C745 FC 04000000  | mov dword ptr ss:[ebp-4],4           |
68854D7C     | 50                | push eax                             |
68854D7D     | 56                | push esi                             |
68854D7E     | E8 2D3E0500       | call wechatwin.688A8BB0              |
68854D83     | 8BC8              | mov ecx,eax                          |
68854D85     | E8 A6002000       | call wechatwin.68A54E30              |
68854D8A     | 84C0              | test al,al                           |
68854D8C     | 75 0C             | jne wechatwin.68854D9A               |
68854D8E     | 56                | push esi                             |
68854D8F     | 8BCB              | mov ecx,ebx                          |
68854D91     | E8 3A832600       | call wechatwin.68ABD0D0              |
68854D96     | 32DB              | xor bl,bl                            |
68854D98     | EB 15             | jmp wechatwin.68854DAF               |
68854D9A     | 6A 01             | push 1                               |
68854D9C     | 53                | push ebx                             |
68854D9D     | 8BD7              | mov edx,edi                          |
68854D9F     | 8D8D 2CF8FFFF     | lea ecx,dword ptr ss:[ebp-7D4]       |
68854DA5     | E8 56FCFFFF       | call wechatwin.68854A00              |
68854DAA     | 83C4 08           | add esp,8                            |

68A4E400-68530000=0x51E400
688A8BB0-68530000=0x378BB0
68A54E30-68530000=0x524E30
68854A00-68530000=0x324A00


Base=68530000
Module=wechatwin.dll
Party=User
Path=C:\Program Files (x86)\Tencent\WeChat\WeChatWin.dll
Status=Unloaded

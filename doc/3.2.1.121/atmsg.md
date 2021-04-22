# search key
```
8d?? ???????? e8 ???????? 83?? ?? 50 8d?? ???????? c6?? ?? ?? e8 ????????
```
#call 
```
66D9CA5B     | 6A 01             | push 1                               |
66D9CA5D     | 57                | push edi                             |
66D9CA5E     | 53                | push ebx                             | ebx:&"纘靎`?靎0"
66D9CA5F     | 8D95 78FFFFFF     | lea edx,dword ptr ss:[ebp-88]        |
66D9CA65     | 8D8D 58FAFFFF     | lea ecx,dword ptr ss:[ebp-5A8]       | [ebp-5A8]:"枨jh"
66D9CA6B     | E8 308C2A00       | call wechatwin.670456A0              | 发送文本、AT消息call
66D9CA70     | 83C4 0C           | add esp,C                            |


EDI=[[[eax]+0x4]+0x34]
```

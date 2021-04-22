# 通过wxid获取个人信息
## search key
```
8d?? ???????? 57 83?? ?? 8d?? ?? 8b?? ???? ?? 50 e8 ????????
```
## key code
```
784CBAC5     | 8DBE 280F0000     | lea edi,dword ptr ds:[esi+F28]  | edi=[esi+f28]【3.2.1.121】通过wxid获取个人详细信息开头
784CBACB     | 57                | push edi                        |
784CBACC     | 83EC 14           | sub esp,14                      |
784CBACF     | 8D45 08           | lea eax,dword ptr ss:[ebp+8]    |
784CBAD2     | 8BCC              | mov ecx,esp                     |
784CBAD4     | 8965 D4           | mov dword ptr ss:[ebp-2C],esp   |
784CBAD7     | 50                | push eax                        |
784CBAD8     | E8 030F3100       | call wechatwin.787DC9E0         |
784CBADD     | C645 FC 01        | mov byte ptr ss:[ebp-4],1       |
784CBAE1     | E8 7A7BDEFF       | call wechatwin.782B3660         |
784CBAE6     | C645 FC 00        | mov byte ptr ss:[ebp-4],0       |
784CBAEA     | E8 517D0A00       | call wechatwin.78573840         | 【3.2.1.121】通过wxid获取个人详细信息
```
## asm code
```
784CBAC5     | 8DBE 280F0000     | lea edi,dword ptr ds:[esi+F28]  | edi=[esi+f28]【3.2.1.121】通过wxid获取个人详细信息开头
784CBACB     | 57                | push edi                        |
784CBACC     | 83EC 14           | sub esp,14                      |
784CBACF     | 8D45 08           | lea eax,dword ptr ss:[ebp+8]    |
784CBAD2     | 8BCC              | mov ecx,esp                     |
784CBAD4     | 8965 D4           | mov dword ptr ss:[ebp-2C],esp   |
784CBAD7     | 50                | push eax                        |
784CBAD8     | E8 030F3100       | call wechatwin.787DC9E0         |
784CBADD     | C645 FC 01        | mov byte ptr ss:[ebp-4],1       |
784CBAE1     | E8 7A7BDEFF       | call wechatwin.782B3660         |
784CBAE6     | C645 FC 00        | mov byte ptr ss:[ebp-4],0       |
784CBAEA     | E8 517D0A00       | call wechatwin.78573840         | 【3.2.1.121】通过wxid获取个人详细信息
784CBAEF     | 84C0              | test al,al                      |
784CBAF1     | 0F84 4C020000     | je wechatwin.784CBD43           |
784CBAF7     | 81EC E0030000     | sub esp,3E0                     |
784CBAFD     | 8BCC              | mov ecx,esp                     |
784CBAFF     | 57                | push edi                        | 【通讯录好友详细信息】
784CBB00     | E8 FBA2EAFF       | call wechatwin.78375E00         |
784CBB05     | 8BCE              | mov ecx,esi                     |
784CBB07     | E8 64020000       | call wechatwin.784CBD70         |
784CBB0C     | 8D45 C0           | lea eax,dword ptr ss:[ebp-40]   |
784CBB0F     | 8BCF              | mov ecx,edi                     |
784CBB11     | 50                | push eax                        |
784CBB12     | E8 3975E1FF       | call wechatwin.782E3050         |
784CBB17     | 8DBE 30130000     | lea edi,dword ptr ds:[esi+1330] |
```
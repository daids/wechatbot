# [wechatwin.dll+0x1A8818C]+0x28
```
04790FF8  69E386A4  ¤.ãi  
04790FFC  00008000  ....  
04791000  00000000  ....  
04791004  00000000  ....  
04791008  00000000  ....  
0479100C  00000000  ....  
04791010  00000000  ....  
04791014  00000000  ....  
04791018  00000000  ....  
0479101C  00008000  ....  
04791020  FFFFFFFF  ÿÿÿÿ  
04791024  FFFFFFFF  ÿÿÿÿ  
04791028  FFFFFFFF  ÿÿÿÿ  
0479102C  00000001  ....  
04791030  00000000  ....  
04791034  048B8648  H...  
04791038  1064D240  @Òd.  
0479103C  00000001  ....  
04791040  1064D2C0  ÀÒd.  
04791044  00000001  ....  
04791048  07221928  (.".  L"MicroMsg.db"
0479104C  0000000B  ....  
04791050  0000000B  ....  
04791054  00000000  ....  
04791058  00000000  ....  
0479105C  048B1298  ....  L"Contact"
04791060  00000007  ....  
04791064  00000007  ....  
04791068  00000000  ....  
0479106C  00000000  ....  
04791070  00000000  ....  
04791074  00000000  ....  
04791078  00000000  ....  
0479107C  00000000  ....  
04791080  00000101  ....  
```

# asm code
```
68B93620     | 55                | push ebp                             |
68B93621     | 8BEC              | mov ebp,esp                          |
68B93623     | 6A FF             | push FFFFFFFF                        |
68B93625     | 68 7018B569       | push wechatwin.69B51870              |
68B9362A     | 64:A1 00000000    | mov eax,dword ptr fs:[0]             |
68B93630     | 50                | push eax                             |
68B93631     | 83EC 0C           | sub esp,C                            |
68B93634     | 53                | push ebx                             |
68B93635     | 56                | push esi                             |
68B93636     | A1 945B086A       | mov eax,dword ptr ds:[6A085B94]      |
68B9363B     | 33C5              | xor eax,ebp                          |
68B9363D     | 50                | push eax                             |
68B9363E     | 8D45 F4           | lea eax,dword ptr ss:[ebp-C]         |
68B93641     | 64:A3 00000000    | mov dword ptr fs:[0],eax             |
68B93647     | 8BF1              | mov esi,ecx                          |
68B93649     | 8B45 08           | mov eax,dword ptr ss:[ebp+8]         |
68B9364C     | 8945 F0           | mov dword ptr ss:[ebp-10],eax        |
68B9364F     | 8D86 BC000000     | lea eax,dword ptr ds:[esi+BC]        | esi+BC:L"default\\theme_default.xml"
68B93655     | C745 FC 00000000  | mov dword ptr ss:[ebp-4],0           |
68B9365C     | 50                | push eax                             |
68B9365D     | 8945 E8           | mov dword ptr ss:[ebp-18],eax        |
68B93660     | C745 EC 00000000  | mov dword ptr ss:[ebp-14],0          |
68B93667     | FF15 60A2C069     | call dword ptr ds:[<&RtlEnterCritica |
68B9366D     | 8D45 0C           | lea eax,dword ptr ss:[ebp+C]         |
68B93670     | C645 FC 01        | mov byte ptr ss:[ebp-4],1            |
68B93674     | 8D9E 8C000000     | lea ebx,dword ptr ds:[esi+8C]        | 【此处是contact header地址】
68B9367A     | 50                | push eax                             |
68B9367B     | 8BCB              | mov ecx,ebx                          |
68B9367D     | E8 4E7CBDFF       | call wechatwin.6876B2D0              |
68B93682     | 8BF0              | mov esi,eax                          |
68B93684     | 3B33              | cmp esi,dword ptr ds:[ebx]           |
68B93686     | 74 13             | je wechatwin.68B9369B                |
68B93688     | 8D46 10           | lea eax,dword ptr ds:[esi+10]        |
68B9368B     | 8BCB              | mov ecx,ebx                          |
68B9368D     | 50                | push eax                             |
68B9368E     | 8D45 0C           | lea eax,dword ptr ss:[ebp+C]         |
68B93691     | 50                | push eax                             |
68B93692     | E8 4970BDFF       | call wechatwin.6876A6E0              |
68B93697     | 84C0              | test al,al                           |
68B93699     | 74 02             | je wechatwin.68B9369D                |
68B9369B     | 8B33              | mov esi,dword ptr ds:[ebx]           |
68B9369D     | 3B33              | cmp esi,dword ptr ds:[ebx]           |
68B9369F     | 74 10             | je wechatwin.68B936B1                |
68B936A1     | 8B4D F0           | mov ecx,dword ptr ss:[ebp-10]        |
68B936A4     | 83C6 28           | add esi,28                           |
68B936A7     | 56                | push esi                             |
68B936A8     | E8 E30BB4FF       | call wechatwin.686D4290              |
68B936AD     | B3 01             | mov bl,1                             |
68B936AF     | EB 02             | jmp wechatwin.68B936B3               |
68B936B1     | 32DB              | xor bl,bl                            |
68B936B3     | FF75 E8           | push dword ptr ss:[ebp-18]           |
68B936B6     | FF15 5CA2C069     | call dword ptr ds:[<&RtlLeaveCritica |
68B936BC     | 8B4D 20           | mov ecx,dword ptr ss:[ebp+20]        |
68B936BF     | 83F9 10           | cmp ecx,10                           |
68B936C2     | 72 0F             | jb wechatwin.68B936D3                |
68B936C4     | 6A 01             | push 1                               |
68B936C6     | 41                | inc ecx                              |
68B936C7     | 51                | push ecx                             |
68B936C8     | FF75 0C           | push dword ptr ss:[ebp+C]            |
68B936CB     | E8 700EB3FF       | call wechatwin.686C4540              |
68B936D0     | 83C4 0C           | add esp,C                            |
68B936D3     | 8AC3              | mov al,bl                            |
68B936D5     | 8B4D F4           | mov ecx,dword ptr ss:[ebp-C]         |
68B936D8     | 64:890D 00000000  | mov dword ptr fs:[0],ecx             |
68B936DF     | 59                | pop ecx                              |
68B936E0     | 5E                | pop esi                              |
68B936E1     | 5B                | pop ebx                              |
68B936E2     | 8BE5              | mov esp,ebp                          |
68B936E4     | 5D                | pop ebp                              |
68B936E5     | C2 1C00           | ret 1C                               |
```
66EFE660     | 50                | push eax                             |
66EFE661     | E8 BA5CE8FF       | call wechatwin.66D84320              |
66EFE666     | 8BC8              | mov ecx,eax                          |
66EFE668     | E8 D3BAFFFF       | call wechatwin.66EFA140              |
66EFE66D     | 8BC8              | mov ecx,eax                          |
66EFE66F     | E8 CCBCCFFF       | call wechatwin.66BFA340              |
66EFE674     | 8D8D 84F1FFFF     | lea ecx,dword ptr ss:[ebp-E7C]       |
66EFE67A     | C645 FC 3E        | mov byte ptr ss:[ebp-4],3E           | 3E:'>'
66EFE67E     | E8 CDE51A00       | call wechatwin.670ACC50              |
66EFE683     | 8D8D 70F1FFFF     | lea ecx,dword ptr ss:[ebp-E90]       |
66EFE689     | E8 C2E51A00       | call wechatwin.670ACC50              |
66EFE68E     | 8B8D 0CF7FFFF     | mov ecx,dword ptr ss:[ebp-8F4]       |
66EFE694     | 8D85 44EBFFFF     | lea eax,dword ptr ss:[ebp-14BC]      |
66EFE69A     | 50                | push eax                             |
66EFE69B     | E8 6091CAFF       | call wechatwin.66BA7800              |
66EFE6A0     | 8D8D 44EBFFFF     | lea ecx,dword ptr ss:[ebp-14BC]      |
66EFE6A6     | E8 D5F3C7FF       | call wechatwin.66B7DA80              |
66EFE6AB     | 8D8D 70F6FFFF     | lea ecx,dword ptr ss:[ebp-990]       |
66EFE6B1     | E8 9AE51A00       | call wechatwin.670ACC50              |
66EFE6B6     | 8D8D 24F2FFFF     | lea ecx,dword ptr ss:[ebp-DDC]       | [ebp-DDC]:"铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪�
66EFE6BC     | E8 8FE51A00       | call wechatwin.670ACC50              |
66EFE6C1     | EB 48             | jmp wechatwin.66EFE70B               |
66EFE6C3     | 8B85 14F4FFFF     | mov eax,dword ptr ss:[ebp-BEC]       | [ebp-BEC]:"铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪铪�
66EFE6C9     | 8985 C0F6FFFF     | mov dword ptr ss:[ebp-940],eax       |
66EFE6CF     | 8B85 18F4FFFF     | mov eax,dword ptr ss:[ebp-BE8]       |
66EFE6D5     | 8985 C4F6FFFF     | mov dword ptr ss:[ebp-93C],eax       |
66EFE6DB     | E8 405CE8FF       | call wechatwin.66D84320              |
66EFE6E0     | FFB5 F0F6FFFF     | push dword ptr ss:[ebp-910]          |
66EFE6E6     | 8D8D C0F6FFFF     | lea ecx,dword ptr ss:[ebp-940]       |
66EFE6EC     | 51                | push ecx                             |
66EFE6ED     | 51                | push ecx                             |
66EFE6EE     | 8D8D D8F2FFFF     | lea ecx,dword ptr ss:[ebp-D28]       |
66EFE6F4     | 51                | push ecx                             |
66EFE6F5     | 8D48 0C           | lea ecx,dword ptr ds:[eax+C]         |
66EFE6F8     | E8 63C6E3FF       | call wechatwin.66D3AD60              |
66EFE6FD     | 8D85 ECF3FFFF     | lea eax,dword ptr ss:[ebp-C14]       |
66EFE703     | 8BCF              | mov ecx,edi                          |
66EFE705     | 50                | push eax                             |
66EFE706     | E8 F590CAFF       | call wechatwin.66BA7800              | 微信消息HOOK
66EFE70B     | 8D8D A4F6FFFF     | lea ecx,dword ptr ss:[ebp-95C]       |
66EFE711     | E8 3AE51A00       | call wechatwin.670ACC50              |
66EFE716     | 8D4D 90           | lea ecx,dword ptr ss:[ebp-70]        |
66EFE719     | E8 328EC7FF       | call wechatwin.66B77550              |
66EFE71E     | 8D8D ECF3FFFF     | lea ecx,dword ptr ss:[ebp-C14]       |
66EFE724     | E8 57F3C7FF       | call wechatwin.66B7DA80              |
66EFE729     | 8D8D C8F6FFFF     | lea ecx,dword ptr ss:[ebp-938]       |
66EFE72F     | E8 1CE51A00       | call wechatwin.670ACC50              |
66EFE734     | 8D8D F4F6FFFF     | lea ecx,dword ptr ss:[ebp-90C]       |
66EFE73A     | E8 11E51A00       | call wechatwin.670ACC50              |
66EFE73F     | 8D4D A8           | lea ecx,dword ptr ss:[ebp-58]        |
66EFE742     | C745 A8 D4A53A68  | mov dword ptr ss:[ebp-58],wechatwin. |
66EFE749     | E8 428D7F00       | call wechatwin.676F7490              |
66EFE74E     | 8D4D A8           | lea ecx,dword ptr ss:[ebp-58]        |
66EFE751     | E8 2ACDC700       | call wechatwin.67B7B480              |
66EFE756     | 8D4D 10           | lea ecx,dword ptr ss:[ebp+10]        |
66EFE759     | C745 10 D4A53A68  | mov dword ptr ss:[ebp+10],wechatwin. |
66EFE760     | E8 2B8D7F00       | call wechatwin.676F7490              |
66EFE765     | 8D4D 10           | lea ecx,dword ptr ss:[ebp+10]        |
66EFE768     | E8 13CDC700       | call wechatwin.67B7B480              |
66EFE76D     | 8B4D F4           | mov ecx,dword ptr ss:[ebp-C]         |
66EFE770     | 64:890D 00000000  | mov dword ptr fs:[0],ecx             |
66EFE777     | 59                | pop ecx                              |
66EFE778     | 5F                | pop edi                              |
66EFE779     | 5E                | pop esi                              |
66EFE77A     | 8B4D F0           | mov ecx,dword ptr ss:[ebp-10]        |
66EFE77D     | 33CD              | xor ecx,ebp                          |
66EFE77F     | E8 F856C700       | call wechatwin.67B73E7C              |
66EFE784     | 8BE5              | mov esp,ebp                          |
66EFE786     | 5D                | pop ebp                              |
66EFE787     | C3                | ret                                  |
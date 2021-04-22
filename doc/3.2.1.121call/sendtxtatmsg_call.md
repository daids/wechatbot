66C2C850     | 55                | push ebp                             |
66C2C851     | 8BEC              | mov ebp,esp                          |
66C2C853     | 6A FF             | push FFFFFFFF                        |
66C2C855     | 68 894CFB67       | push wechatwin.67FB4C89              |
66C2C85A     | 64:A1 00000000    | mov eax,dword ptr fs:[0]             |
66C2C860     | 50                | push eax                             |
66C2C861     | B8 04100000       | mov eax,1004                         |
66C2C866     | E8 9581F400       | call wechatwin.67B74A00              |
66C2C86B     | A1 945B5368       | mov eax,dword ptr ds:[68535B94]      |
66C2C870     | 33C5              | xor eax,ebp                          |
66C2C872     | 8945 F0           | mov dword ptr ss:[ebp-10],eax        |
66C2C875     | 53                | push ebx                             |
66C2C876     | 56                | push esi                             |
66C2C877     | 57                | push edi                             |
66C2C878     | 50                | push eax                             |
66C2C879     | 8D45 F4           | lea eax,dword ptr ss:[ebp-C]         |
66C2C87C     | 64:A3 00000000    | mov dword ptr fs:[0],eax             |
66C2C882     | 8BD9              | mov ebx,ecx                          |
66C2C884     | 895D B4           | mov dword ptr ss:[ebp-4C],ebx        |
66C2C887     | 8D43 18           | lea eax,dword ptr ds:[ebx+18]        |
66C2C88A     | C745 FC 00000000  | mov dword ptr ss:[ebp-4],0           |
66C2C891     | 8378 04 00        | cmp dword ptr ds:[eax+4],0           |
66C2C895     | 8B7D 10           | mov edi,dword ptr ss:[ebp+10]        |
66C2C898     | 8945 98           | mov dword ptr ss:[ebp-68],eax        |
66C2C89B     | 0F9EC0            | setle al                             |
66C2C89E     | 84C0              | test al,al                           |
66C2C8A0     | 74 09             | je wechatwin.66C2C8AB                |
66C2C8A2     | 85FF              | test edi,edi                         |
66C2C8A4     | 0F9EC0            | setle al                             |
66C2C8A7     | 84C0              | test al,al                           |
66C2C8A9     | 75 1F             | jne wechatwin.66C2C8CA               |
66C2C8AB     | 8B45 08           | mov eax,dword ptr ss:[ebp+8]         |
66C2C8AE     | 8B48 04           | mov ecx,dword ptr ds:[eax+4]         |
66C2C8B1     | 8BD1              | mov edx,ecx                          |
66C2C8B3     | 8B30              | mov esi,dword ptr ds:[eax]           |
66C2C8B5     | 2BD6              | sub edx,esi                          |
66C2C8B7     | B8 398EE338       | mov eax,38E38E39                     |
66C2C8BC     | F7EA              | imul edx                             |
66C2C8BE     | C1FA 04           | sar edx,4                            |
66C2C8C1     | 8BC2              | mov eax,edx                          |
66C2C8C3     | C1E8 1F           | shr eax,1F                           |
66C2C8C6     | 03C2              | add eax,edx                          |
66C2C8C8     | 75 07             | jne wechatwin.66C2C8D1               |
66C2C8CA     | 32DB              | xor bl,bl                            |
66C2C8CC     | E9 DA080000       | jmp wechatwin.66C2D1AB               |
66C2C8D1     | 3BF1              | cmp esi,ecx                          |
66C2C8D3     | 0F84 83080000     | je wechatwin.66C2D15C                |
66C2C8D9     | 8D5E 04           | lea ebx,dword ptr ds:[esi+4]         |
66C2C8DC     | 0F1F40 00         | nop dword ptr ds:[eax],eax           |
66C2C8E0     | 85FF              | test edi,edi                         |
66C2C8E2     | C745 88 00000000  | mov dword ptr ss:[ebp-78],0          |
66C2C8E9     | 8D4D 0C           | lea ecx,dword ptr ss:[ebp+C]         |
66C2C8EC     | 0F57C0            | xorps xmm0,xmm0                      |
66C2C8EF     | 0F9EC0            | setle al                             |
66C2C8F2     | 84C0              | test al,al                           |
66C2C8F4     | 6A FF             | push FFFFFFFF                        |
66C2C8F6     | 0F454D 98         | cmovne ecx,dword ptr ss:[ebp-68]     |
66C2C8FA     | 0F1185 78FFFFFF   | movups xmmword ptr ss:[ebp-88],xmm0  |
66C2C901     | FF31              | push dword ptr ds:[ecx]              |
66C2C903     | 8D8D 78FFFFFF     | lea ecx,dword ptr ss:[ebp-88]        |
66C2C909     | E8 52044800       | call wechatwin.670ACD60              |
66C2C90E     | 8D7B 34           | lea edi,dword ptr ds:[ebx+34]        |
66C2C911     | C645 FC 01        | mov byte ptr ss:[ebp-4],1            |
66C2C915     | 8B47 F8           | mov eax,dword ptr ds:[edi-8]         |
66C2C918     | 0B47 FC           | or eax,dword ptr ds:[edi-4]          |
66C2C91B     | 0F84 C1000000     | je wechatwin.66C2C9E2                |
66C2C921     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2C927     | E8 C41AF5FF       | call wechatwin.66B7E3F0              |
66C2C92C     | C645 FC 02        | mov byte ptr ss:[ebp-4],2            |
66C2C930     | A1 6C725C68       | mov eax,dword ptr ds:[685C726C]      |
66C2C935     | A8 01             | test al,1                            |
66C2C937     | 75 22             | jne wechatwin.66C2C95B               |
66C2C939     | 83C8 01           | or eax,1                             |
66C2C93C     | A3 6C725C68       | mov dword ptr ds:[685C726C],eax      |
66C2C941     | C645 FC 03        | mov byte ptr ss:[ebp-4],3            |
66C2C945     | E8 86F41D00       | call wechatwin.66E0BDD0              |
66C2C94A     | 68 606B0968       | push wechatwin.68096B60              |
66C2C94F     | E8 B878F400       | call wechatwin.67B7420C              |
66C2C954     | 83C4 04           | add esp,4                            |
66C2C957     | C645 FC 02        | mov byte ptr ss:[ebp-4],2            |
66C2C95B     | FF77 FC           | push dword ptr ds:[edi-4]            |
66C2C95E     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2C964     | FF77 F8           | push dword ptr ds:[edi-8]            |
66C2C967     | E8 A47D1E00       | call wechatwin.66E14710              |
66C2C96C     | 83C4 08           | add esp,8                            |
66C2C96F     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2C975     | E8 B6A83F00       | call wechatwin.67027230              |
66C2C97A     | 0BC2              | or eax,edx                           |
66C2C97C     | 74 55             | je wechatwin.66C2C9D3                |
66C2C97E     | A1 C8715C68       | mov eax,dword ptr ds:[685C71C8]      |
66C2C983     | A8 01             | test al,1                            |
66C2C985     | 75 22             | jne wechatwin.66C2C9A9               |
66C2C987     | 83C8 01           | or eax,1                             |
66C2C98A     | A3 C8715C68       | mov dword ptr ds:[685C71C8],eax      |
66C2C98F     | C645 FC 04        | mov byte ptr ss:[ebp-4],4            |
66C2C993     | E8 D8121B00       | call wechatwin.66DDDC70              |
66C2C998     | 68 60660968       | push wechatwin.68096660              |
66C2C99D     | E8 6A78F400       | call wechatwin.67B7420C              |
66C2C9A2     | 83C4 04           | add esp,4                            |
66C2C9A5     | C645 FC 02        | mov byte ptr ss:[ebp-4],2            |
66C2C9A9     | 57                | push edi                             |
66C2C9AA     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
66C2C9B0     | B9 60715C68       | mov ecx,wechatwin.685C7160           | 685C7160:&"0孑f@掭fw"
66C2C9B5     | 50                | push eax                             |
66C2C9B6     | 53                | push ebx                             |
66C2C9B7     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2C9BD     | 50                | push eax                             |
66C2C9BE     | E8 0D6E1B00       | call wechatwin.66DE37D0              |
66C2C9C3     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2C9C9     | E8 B210F5FF       | call wechatwin.66B7DA80              |
66C2C9CE     | E9 61070000       | jmp wechatwin.66C2D134               |
66C2C9D3     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2C9D9     | C645 FC 01        | mov byte ptr ss:[ebp-4],1            |
66C2C9DD     | E8 9E10F5FF       | call wechatwin.66B7DA80              |
66C2C9E2     | 8B06              | mov eax,dword ptr ds:[esi]           |
66C2C9E4     | 48                | dec eax                              |
66C2C9E5     | 83F8 05           | cmp eax,5                            |
66C2C9E8     | 0F87 46070000     | ja wechatwin.66C2D134                |
66C2C9EE     | FF2485 D4D1C266   | jmp dword ptr ds:[eax*4+66C2D1D4]    |
66C2C9F5     | 8B03              | mov eax,dword ptr ds:[ebx]           |
66C2C9F7     | 85C0              | test eax,eax                         |
66C2C9F9     | 74 06             | je wechatwin.66C2CA01                |
66C2C9FB     | 66:8338 00        | cmp word ptr ds:[eax],0              |
66C2C9FF     | 75 05             | jne wechatwin.66C2CA06               |
66C2CA01     | B8 C8B92F68       | mov eax,wechatwin.682FB9C8           |
66C2CA06     | 6A FF             | push FFFFFFFF                        |
66C2CA08     | 50                | push eax                             |
66C2CA09     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CA0C     | E8 8FFF4700       | call wechatwin.670AC9A0              |
66C2CA11     | 33D2              | xor edx,edx                          |
66C2CA13     | C645 FC 05        | mov byte ptr ss:[ebp-4],5            |
66C2CA17     | 3955 A0           | cmp dword ptr ss:[ebp-60],edx        |
66C2CA1A     | 0F8E F4000000     | jle wechatwin.66C2CB14               |
66C2CA20     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CA23     | E8 88064800       | call wechatwin.670AD0B0              |
66C2CA28     | 8B4D A0           | mov ecx,dword ptr ss:[ebp-60]        |
66C2CA2B     | 8945 BC           | mov dword ptr ss:[ebp-44],eax        |
66C2CA2E     | 66:90             | nop                                  |
66C2CA30     | 0FB70450          | movzx eax,word ptr ds:[eax+edx*2]    |
66C2CA34     | 83F8 20           | cmp eax,20                           | 20:' '
66C2CA37     | 74 0F             | je wechatwin.66C2CA48                |
66C2CA39     | 83F8 0A           | cmp eax,A                            | A:'\n'
66C2CA3C     | 74 0A             | je wechatwin.66C2CA48                |
66C2CA3E     | 83F8 09           | cmp eax,9                            | 9:'\t'
66C2CA41     | 74 05             | je wechatwin.66C2CA48                |
66C2CA43     | 83F8 0D           | cmp eax,D                            | D:'\r'
66C2CA46     | 75 0E             | jne wechatwin.66C2CA56               |
66C2CA48     | 42                | inc edx                              |
66C2CA49     | 3BD1              | cmp edx,ecx                          |
66C2CA4B     | 0F8D C3000000     | jge wechatwin.66C2CB14               |
66C2CA51     | 8B45 BC           | mov eax,dword ptr ss:[ebp-44]        |
66C2CA54     | EB DA             | jmp wechatwin.66C2CA30               |
66C2CA56     | E8 C56CF5FF       | call wechatwin.66B83720              |
66C2CA5B     | 6A 01             | push 1                               |
66C2CA5D     | 57                | push edi                             |
66C2CA5E     | 53                | push ebx                             |
66C2CA5F     | 8D95 78FFFFFF     | lea edx,dword ptr ss:[ebp-88]        |
66C2CA65     | 8D8D 58FAFFFF     | lea ecx,dword ptr ss:[ebp-5A8]       |
66C2CA6B     | E8 308C2A00       | call wechatwin.66ED56A0              | 发送文本、AT消息call
66C2CA70     | 83C4 0C           | add esp,C                            |
66C2CA73     | 50                | push eax                             |
66C2CA74     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CA7A     | C645 FC 06        | mov byte ptr ss:[ebp-4],6            |
66C2CA7E     | E8 6DEBF4FF       | call wechatwin.66B7B5F0              |
66C2CA83     | 8D8D 58FAFFFF     | lea ecx,dword ptr ss:[ebp-5A8]       |
66C2CA89     | C645 FC 08        | mov byte ptr ss:[ebp-4],8            |
66C2CA8D     | E8 EE0FF5FF       | call wechatwin.66B7DA80              |
66C2CA92     | E8 E9EB1D00       | call wechatwin.66E0B680              |
66C2CA97     | 8BC8              | mov ecx,eax                          |
66C2CA99     | E8 92A73F00       | call wechatwin.67027230              |
66C2CA9E     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CAA4     | 8955 BC           | mov dword ptr ss:[ebp-44],edx        |
66C2CAA7     | 8BF8              | mov edi,eax                          |
66C2CAA9     | E8 82A73F00       | call wechatwin.67027230              |
66C2CAAE     | 3BC7              | cmp eax,edi                          |
66C2CAB0     | 75 05             | jne wechatwin.66C2CAB7               |
66C2CAB2     | 3B55 BC           | cmp edx,dword ptr ss:[ebp-44]        |
66C2CAB5     | 74 45             | je wechatwin.66C2CAFC                |
66C2CAB7     | 8B7D B4           | mov edi,dword ptr ss:[ebp-4C]        |
66C2CABA     | 8BCF              | mov ecx,edi                          |
66C2CABC     | E8 2F270000       | call wechatwin.66C2F1F0              |
66C2CAC1     | 84C0              | test al,al                           |
66C2CAC3     | 74 37             | je wechatwin.66C2CAFC                |
66C2CAC5     | 8D45 0C           | lea eax,dword ptr ss:[ebp+C]         |
66C2CAC8     | 50                | push eax                             |
66C2CAC9     | 8D4F 18           | lea ecx,dword ptr ds:[edi+18]        | [edi+18]:"牨說%"
66C2CACC     | E8 7F064800       | call wechatwin.670AD150              |
66C2CAD1     | 84C0              | test al,al                           |
66C2CAD3     | 74 27             | je wechatwin.66C2CAFC                |
66C2CAD5     | 6A 01             | push 1                               |
66C2CAD7     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CADD     | 8BCF              | mov ecx,edi                          |
66C2CADF     | 50                | push eax                             |
66C2CAE0     | 8D85 40FFFFFF     | lea eax,dword ptr ss:[ebp-C0]        |
66C2CAE6     | 50                | push eax                             |
66C2CAE7     | E8 34100000       | call wechatwin.66C2DB20              |
66C2CAEC     | 8D45 9C           | lea eax,dword ptr ss:[ebp-64]        |
66C2CAEF     | 50                | push eax                             |
66C2CAF0     | E8 9BBEFFFF       | call wechatwin.66C28990              |
66C2CAF5     | 8BC8              | mov ecx,eax                          |
66C2CAF7     | E8 64E51D00       | call wechatwin.66E0B060              |
66C2CAFC     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CB02     | E8 790FF5FF       | call wechatwin.66B7DA80              |
66C2CB07     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CB0A     | E8 41014800       | call wechatwin.670ACC50              |
66C2CB0F     | E9 20060000       | jmp wechatwin.66C2D134               |
66C2CB14     | 8B45 08           | mov eax,dword ptr ss:[ebp+8]         |
66C2CB17     | 8B48 04           | mov ecx,dword ptr ds:[eax+4]         |
66C2CB1A     | 2B08              | sub ecx,dword ptr ds:[eax]           |
66C2CB1C     | B8 398EE338       | mov eax,38E38E39                     |
66C2CB21     | F7E9              | imul ecx                             |
66C2CB23     | C1FA 04           | sar edx,4                            |
66C2CB26     | 8BC2              | mov eax,edx                          |
66C2CB28     | C1E8 1F           | shr eax,1F                           |
66C2CB2B     | 03C2              | add eax,edx                          |
66C2CB2D     | 83F8 01           | cmp eax,1                            |
66C2CB30     | 75 30             | jne wechatwin.66C2CB62               |
66C2CB32     | 68 80000000       | push 80                              |
66C2CB37     | E8 5173F400       | call wechatwin.67B73E8D              |
66C2CB3C     | 83C4 04           | add esp,4                            |
66C2CB3F     | 8945 BC           | mov dword ptr ss:[ebp-44],eax        |
66C2CB42     | 8BC8              | mov ecx,eax                          |
66C2CB44     | FF75 98           | push dword ptr ss:[ebp-68]           |
66C2CB47     | E8 24863000       | call wechatwin.66F35170              |
66C2CB4C     | 50                | push eax                             |
66C2CB4D     | 6A 00             | push 0                               |
66C2CB4F     | 6A 00             | push 0                               |
66C2CB51     | 68 2E030000       | push 32E                             |
66C2CB56     | E8 25563000       | call wechatwin.66F32180              |
66C2CB5B     | 8BC8              | mov ecx,eax                          |
66C2CB5D     | E8 0E693000       | call wechatwin.66F33470              |
66C2CB62     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CB65     | E8 E6004800       | call wechatwin.670ACC50              |
66C2CB6A     | E9 C5050000       | jmp wechatwin.66C2D134               |
66C2CB6F     | 83EC 14           | sub esp,14                           |
66C2CB72     | 8D47 E0           | lea eax,dword ptr ds:[edi-20]        |
66C2CB75     | 8BCC              | mov ecx,esp                          |
66C2CB77     | 8965 BC           | mov dword ptr ss:[ebp-44],esp        |
66C2CB7A     | 50                | push eax                             |
66C2CB7B     | E8 60FE4700       | call wechatwin.670AC9E0              |
66C2CB80     | 53                | push ebx                             |
66C2CB81     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
66C2CB87     | C645 FC 09        | mov byte ptr ss:[ebp-4],9            | 9:'\t'
66C2CB8B     | 50                | push eax                             |
66C2CB8C     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CB92     | 50                | push eax                             |
66C2CB93     | E8 886BF5FF       | call wechatwin.66B83720              |
66C2CB98     | 8BC8              | mov ecx,eax                          |
66C2CB9A     | C645 FC 01        | mov byte ptr ss:[ebp-4],1            |
66C2CB9E     | E8 BD832A00       | call wechatwin.66ED4F60              |
66C2CBA3     | C645 FC 0A        | mov byte ptr ss:[ebp-4],A            | A:'\n'
66C2CBA7     | E8 D4EA1D00       | call wechatwin.66E0B680              |
66C2CBAC     | 8BC8              | mov ecx,eax                          |
66C2CBAE     | E8 7DA63F00       | call wechatwin.67027230              |
66C2CBB3     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CBB9     | 8955 BC           | mov dword ptr ss:[ebp-44],edx        |
66C2CBBC     | 8BF8              | mov edi,eax                          |
66C2CBBE     | E8 6DA63F00       | call wechatwin.67027230              |
66C2CBC3     | 3BC7              | cmp eax,edi                          |
66C2CBC5     | 75 43             | jne wechatwin.66C2CC0A               |
66C2CBC7     | 3B55 BC           | cmp edx,dword ptr ss:[ebp-44]        |
66C2CBCA     | 75 3E             | jne wechatwin.66C2CC0A               |
66C2CBCC     | E8 AF6BF5FF       | call wechatwin.66B83780              |
66C2CBD1     | 6A 00             | push 0                               |
66C2CBD3     | 6A 01             | push 1                               |
66C2CBD5     | 6A 01             | push 1                               |
66C2CBD7     | 6A 0D             | push D                               |
66C2CBD9     | 6A 5F             | push 5F                              |
66C2CBDB     | E8 A0A1F500       | call wechatwin.67B86D80              |
66C2CBE0     | 83C4 14           | add esp,14                           |
66C2CBE3     | E8 986BF5FF       | call wechatwin.66B83780              |
66C2CBE8     | 6A 00             | push 0                               |
66C2CBEA     | 6A 01             | push 1                               |
66C2CBEC     | 6A 01             | push 1                               |
66C2CBEE     | 6A 10             | push 10                              |
66C2CBF0     | 6A 5F             | push 5F                              |
66C2CBF2     | E8 89A1F500       | call wechatwin.67B86D80              |
66C2CBF7     | 83C4 14           | add esp,14                           |
66C2CBFA     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CC00     | E8 7B0EF5FF       | call wechatwin.66B7DA80              |
66C2CC05     | E9 2A050000       | jmp wechatwin.66C2D134               |
66C2CC0A     | 8B7D B4           | mov edi,dword ptr ss:[ebp-4C]        |
66C2CC0D     | 8B8F 68040000     | mov ecx,dword ptr ds:[edi+468]       |
66C2CC13     | 85C9              | test ecx,ecx                         |
66C2CC15     | 74 0B             | je wechatwin.66C2CC22                |
66C2CC17     | 8B01              | mov eax,dword ptr ds:[ecx]           |
66C2CC19     | 8B40 24           | mov eax,dword ptr ds:[eax+24]        |
66C2CC1C     | FFD0              | call eax                             |
66C2CC1E     | 84C0              | test al,al                           |
66C2CC20     | 74 27             | je wechatwin.66C2CC49                |
66C2CC22     | 8D45 0C           | lea eax,dword ptr ss:[ebp+C]         |
66C2CC25     | 50                | push eax                             |
66C2CC26     | 8D4F 18           | lea ecx,dword ptr ds:[edi+18]        | [edi+18]:"牨說%"
66C2CC29     | E8 22054800       | call wechatwin.670AD150              |
66C2CC2E     | 84C0              | test al,al                           |
66C2CC30     | 74 17             | je wechatwin.66C2CC49                |
66C2CC32     | 6A 01             | push 1                               |
66C2CC34     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CC3A     | 8BCF              | mov ecx,edi                          |
66C2CC3C     | 50                | push eax                             |
66C2CC3D     | 8D85 3CFFFFFF     | lea eax,dword ptr ss:[ebp-C4]        |
66C2CC43     | 50                | push eax                             |
66C2CC44     | E8 D70E0000       | call wechatwin.66C2DB20              |
66C2CC49     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CC4F     | E8 2C0EF5FF       | call wechatwin.66B7DA80              |
66C2CC54     | E9 DB040000       | jmp wechatwin.66C2D134               |
66C2CC59     | 53                | push ebx                             |
66C2CC5A     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CC5D     | E8 7EFD4700       | call wechatwin.670AC9E0              |
66C2CC62     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CC65     | E8 86034700       | call wechatwin.6709CFF0              |
66C2CC6A     | 84C0              | test al,al                           |
66C2CC6C     | 0F84 40010000     | je wechatwin.66C2CDB2                |
66C2CC72     | 8D8D 44FFFFFF     | lea ecx,dword ptr ss:[ebp-BC]        |
66C2CC78     | C645 BB 00        | mov byte ptr ss:[ebp-45],0           |
66C2CC7C     | E8 8FDD4600       | call wechatwin.6709AA10              |
66C2CC81     | 8B85 44FFFFFF     | mov eax,dword ptr ss:[ebp-BC]        |
66C2CC87     | 85C0              | test eax,eax                         |
66C2CC89     | 74 06             | je wechatwin.66C2CC91                |
66C2CC8B     | 66:8338 00        | cmp word ptr ds:[eax],0              |
66C2CC8F     | 75 05             | jne wechatwin.66C2CC96               |
66C2CC91     | B8 C8B92F68       | mov eax,wechatwin.682FB9C8           |
66C2CC96     | 50                | push eax                             |
66C2CC97     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CC9A     | E8 21074800       | call wechatwin.670AD3C0              |
66C2CC9F     | 0FB64D BB         | movzx ecx,byte ptr ss:[ebp-45]       |
66C2CCA3     | 84C0              | test al,al                           |
66C2CCA5     | B8 01000000       | mov eax,1                            |
66C2CCAA     | 0F45C8            | cmovne ecx,eax                       |
66C2CCAD     | 83EC 14           | sub esp,14                           |
66C2CCB0     | 884D 94           | mov byte ptr ss:[ebp-6C],cl          |
66C2CCB3     | 8D47 E0           | lea eax,dword ptr ds:[edi-20]        |
66C2CCB6     | 8BCC              | mov ecx,esp                          |
66C2CCB8     | 8965 BC           | mov dword ptr ss:[ebp-44],esp        |
66C2CCBB     | 50                | push eax                             |
66C2CCBC     | E8 1FFD4700       | call wechatwin.670AC9E0              |
66C2CCC1     | FF75 94           | push dword ptr ss:[ebp-6C]           |
66C2CCC4     | 83EC 14           | sub esp,14                           |
66C2CCC7     | 8BCC              | mov ecx,esp                          |
66C2CCC9     | 8965 90           | mov dword ptr ss:[ebp-70],esp        |
66C2CCCC     | 6A FF             | push FFFFFFFF                        |
66C2CCCE     | 68 C8B92F68       | push wechatwin.682FB9C8              |
66C2CCD3     | E8 C8FC4700       | call wechatwin.670AC9A0              |
66C2CCD8     | 83EC 14           | sub esp,14                           |
66C2CCDB     | 8BCC              | mov ecx,esp                          |
66C2CCDD     | 8965 8C           | mov dword ptr ss:[ebp-74],esp        |
66C2CCE0     | 53                | push ebx                             |
66C2CCE1     | E8 FAFC4700       | call wechatwin.670AC9E0              |
66C2CCE6     | 83EC 14           | sub esp,14                           |
66C2CCE9     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
66C2CCEF     | 8BCC              | mov ecx,esp                          |
66C2CCF1     | 8965 B0           | mov dword ptr ss:[ebp-50],esp        |
66C2CCF4     | 50                | push eax                             |
66C2CCF5     | E8 E6FC4700       | call wechatwin.670AC9E0              |
66C2CCFA     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CD00     | C645 FC 10        | mov byte ptr ss:[ebp-4],10           |
66C2CD04     | 50                | push eax                             |
66C2CD05     | E8 36BDF5FF       | call wechatwin.66B88A40              |
66C2CD0A     | 8BC8              | mov ecx,eax                          |
66C2CD0C     | C645 FC 0C        | mov byte ptr ss:[ebp-4],C            | C:'\f'
66C2CD10     | E8 CB3E1B00       | call wechatwin.66DE0BE0              |
66C2CD15     | C645 FC 11        | mov byte ptr ss:[ebp-4],11           |
66C2CD19     | E8 62E91D00       | call wechatwin.66E0B680              |
66C2CD1E     | 8BC8              | mov ecx,eax                          |
66C2CD20     | E8 0BA53F00       | call wechatwin.67027230              |
66C2CD25     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CD2B     | 8955 BC           | mov dword ptr ss:[ebp-44],edx        |
66C2CD2E     | 8BF8              | mov edi,eax                          |
66C2CD30     | E8 FBA43F00       | call wechatwin.67027230              |
66C2CD35     | 3BC7              | cmp eax,edi                          |
66C2CD37     | 75 05             | jne wechatwin.66C2CD3E               |
66C2CD39     | 3B55 BC           | cmp edx,dword ptr ss:[ebp-44]        |
66C2CD3C     | 74 5E             | je wechatwin.66C2CD9C                |
66C2CD3E     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CD44     | E8 E7A43F00       | call wechatwin.67027230              |
66C2CD49     | 8B7D B4           | mov edi,dword ptr ss:[ebp-4C]        |
66C2CD4C     | 8985 58FFFFFF     | mov dword ptr ss:[ebp-A8],eax        |
66C2CD52     | 8D85 58FFFFFF     | lea eax,dword ptr ss:[ebp-A8]        |
66C2CD58     | 50                | push eax                             |
66C2CD59     | 8995 5CFFFFFF     | mov dword ptr ss:[ebp-A4],edx        |
66C2CD5F     | 8D8F 40040000     | lea ecx,dword ptr ds:[edi+440]       |
66C2CD65     | E8 F6270000       | call wechatwin.66C2F560              |
66C2CD6A     | 8BCF              | mov ecx,edi                          |
66C2CD6C     | E8 7F240000       | call wechatwin.66C2F1F0              |
66C2CD71     | 84C0              | test al,al                           |
66C2CD73     | 74 27             | je wechatwin.66C2CD9C                |
66C2CD75     | 8D45 0C           | lea eax,dword ptr ss:[ebp+C]         |
66C2CD78     | 50                | push eax                             |
66C2CD79     | 8D4F 18           | lea ecx,dword ptr ds:[edi+18]        | [edi+18]:"牨說%"
66C2CD7C     | E8 CF034800       | call wechatwin.670AD150              |
66C2CD81     | 84C0              | test al,al                           |
66C2CD83     | 74 17             | je wechatwin.66C2CD9C                |
66C2CD85     | 6A 01             | push 1                               |
66C2CD87     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CD8D     | 8BCF              | mov ecx,edi                          |
66C2CD8F     | 50                | push eax                             |
66C2CD90     | 8D85 38FFFFFF     | lea eax,dword ptr ss:[ebp-C8]        |
66C2CD96     | 50                | push eax                             |
66C2CD97     | E8 840D0000       | call wechatwin.66C2DB20              |
66C2CD9C     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CDA2     | E8 D90CF5FF       | call wechatwin.66B7DA80              |
66C2CDA7     | 8D8D 44FFFFFF     | lea ecx,dword ptr ss:[ebp-BC]        |
66C2CDAD     | E8 9EFE4700       | call wechatwin.670ACC50              |
66C2CDB2     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CDB5     | E8 96FE4700       | call wechatwin.670ACC50              |
66C2CDBA     | E9 75030000       | jmp wechatwin.66C2D134               |
66C2CDBF     | 8D8D 78FFFFFF     | lea ecx,dword ptr ss:[ebp-88]        |
66C2CDC5     | E8 C6005F00       | call wechatwin.6721CE90              |
66C2CDCA     | 84C0              | test al,al                           |
66C2CDCC     | 0F85 62030000     | jne wechatwin.66C2D134               |
66C2CDD2     | 8BCB              | mov ecx,ebx                          |
66C2CDD4     | E8 17024700       | call wechatwin.6709CFF0              |
66C2CDD9     | 84C0              | test al,al                           |
66C2CDDB     | 0F84 53030000     | je wechatwin.66C2D134                |
66C2CDE1     | E8 9A69F5FF       | call wechatwin.66B83780              |
66C2CDE6     | 6A 02             | push 2                               |
66C2CDE8     | E8 C3242600       | call wechatwin.66E8F2B0              |
66C2CDED     | 6A 00             | push 0                               |
66C2CDEF     | 83EC 14           | sub esp,14                           |
66C2CDF2     | 8BCC              | mov ecx,esp                          |
66C2CDF4     | 8965 B0           | mov dword ptr ss:[ebp-50],esp        |
66C2CDF7     | 6A FF             | push FFFFFFFF                        |
66C2CDF9     | 68 C8B92F68       | push wechatwin.682FB9C8              |
66C2CDFE     | E8 9DFB4700       | call wechatwin.670AC9A0              |
66C2CE03     | 6A 02             | push 2                               |
66C2CE05     | 83EC 14           | sub esp,14                           |
66C2CE08     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
66C2CE0E     | 8BCC              | mov ecx,esp                          |
66C2CE10     | 8965 8C           | mov dword ptr ss:[ebp-74],esp        |
66C2CE13     | 50                | push eax                             |
66C2CE14     | E8 C7FB4700       | call wechatwin.670AC9E0              |
66C2CE19     | 83EC 14           | sub esp,14                           |
66C2CE1C     | 8BCC              | mov ecx,esp                          |
66C2CE1E     | 8965 90           | mov dword ptr ss:[ebp-70],esp        |
66C2CE21     | 6A FF             | push FFFFFFFF                        |
66C2CE23     | 68 C8B92F68       | push wechatwin.682FB9C8              |
66C2CE28     | E8 73FB4700       | call wechatwin.670AC9A0              |
66C2CE2D     | 83EC 14           | sub esp,14                           |
66C2CE30     | 8BCC              | mov ecx,esp                          |
66C2CE32     | 8965 BC           | mov dword ptr ss:[ebp-44],esp        |
66C2CE35     | 53                | push ebx                             |
66C2CE36     | E8 A5FB4700       | call wechatwin.670AC9E0              |
66C2CE3B     | C645 FC 15        | mov byte ptr ss:[ebp-4],15           |
66C2CE3F     | E8 8CACF8FF       | call wechatwin.66BB7AD0              |
66C2CE44     | 8BC8              | mov ecx,eax                          |
66C2CE46     | C645 FC 01        | mov byte ptr ss:[ebp-4],1            |
66C2CE4A     | E8 91002200       | call wechatwin.66E4CEE0              |
66C2CE4F     | E9 E0020000       | jmp wechatwin.66C2D134               |
66C2CE54     | 8D8D 78FFFFFF     | lea ecx,dword ptr ss:[ebp-88]        |
66C2CE5A     | E8 31005F00       | call wechatwin.6721CE90              |
66C2CE5F     | 84C0              | test al,al                           |
66C2CE61     | 0F85 CD020000     | jne wechatwin.66C2D134               |
66C2CE67     | 53                | push ebx                             |
66C2CE68     | 8D8D 44FFFFFF     | lea ecx,dword ptr ss:[ebp-BC]        |
66C2CE6E     | E8 6DFB4700       | call wechatwin.670AC9E0              |
66C2CE73     | 8D8D 44FFFFFF     | lea ecx,dword ptr ss:[ebp-BC]        |
66C2CE79     | C645 FC 16        | mov byte ptr ss:[ebp-4],16           |
66C2CE7D     | E8 6E014700       | call wechatwin.6709CFF0              |
66C2CE82     | 84C0              | test al,al                           |
66C2CE84     | 0F84 96010000     | je wechatwin.66C2D020                |
66C2CE8A     | 8BCB              | mov ecx,ebx                          |
66C2CE8C     | E8 1F024800       | call wechatwin.670AD0B0              |
66C2CE91     | 8BD0              | mov edx,eax                          |
66C2CE93     | 8D4D D8           | lea ecx,dword ptr ss:[ebp-28]        |
66C2CE96     | E8 35404900       | call wechatwin.670C0ED0              |
66C2CE9B     | 6A 00             | push 0                               |
66C2CE9D     | 50                | push eax                             |
66C2CE9E     | 8D8D 0CFFFFFF     | lea ecx,dword ptr ss:[ebp-F4]        |
66C2CEA4     | E8 47FC4700       | call wechatwin.670ACAF0              |
66C2CEA9     | 8D4D D8           | lea ecx,dword ptr ss:[ebp-28]        |
66C2CEAC     | C645 FC 17        | mov byte ptr ss:[ebp-4],17           |
66C2CEB0     | E8 9BA6F4FF       | call wechatwin.66B77550              |
66C2CEB5     | E8 563C4900       | call wechatwin.670C0B10              |
66C2CEBA     | 52                | push edx                             |
66C2CEBB     | 50                | push eax                             |
66C2CEBC     | 8D4D C0           | lea ecx,dword ptr ss:[ebp-40]        |
66C2CEBF     | E8 BC484900       | call wechatwin.670C1780              |
66C2CEC4     | 83C4 08           | add esp,8                            |
66C2CEC7     | 8D8D 20FFFFFF     | lea ecx,dword ptr ss:[ebp-E0]        |
66C2CECD     | 6A 00             | push 0                               |
66C2CECF     | 50                | push eax                             |
66C2CED0     | E8 1BFC4700       | call wechatwin.670ACAF0              |
66C2CED5     | 8D4D C0           | lea ecx,dword ptr ss:[ebp-40]        |
66C2CED8     | C645 FC 18        | mov byte ptr ss:[ebp-4],18           |
66C2CEDC     | E8 6FA6F4FF       | call wechatwin.66B77550              |
66C2CEE1     | E8 FA74F7FF       | call wechatwin.66BA43E0              |
66C2CEE6     | E8 659E1E00       | call wechatwin.66E16D50              |
66C2CEEB     | 52                | push edx                             |
66C2CEEC     | 50                | push eax                             |
66C2CEED     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CEF0     | E8 FBE72600       | call wechatwin.66E9B6F0              |
66C2CEF5     | 83C4 08           | add esp,8                            |
66C2CEF8     | 8B85 20FFFFFF     | mov eax,dword ptr ss:[ebp-E0]        |
66C2CEFE     | 85C0              | test eax,eax                         |
66C2CF00     | 74 06             | je wechatwin.66C2CF08                |
66C2CF02     | 66:8338 00        | cmp word ptr ds:[eax],0              |
66C2CF06     | 75 05             | jne wechatwin.66C2CF0D               |
66C2CF08     | B8 C8B92F68       | mov eax,wechatwin.682FB9C8           |
66C2CF0D     | 50                | push eax                             |
66C2CF0E     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CF11     | E8 3A004800       | call wechatwin.670ACF50              |
66C2CF16     | 68 A4622368       | push wechatwin.682362A4              | 682362A4:L".gif"
66C2CF1B     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2CF1E     | E8 2D004800       | call wechatwin.670ACF50              |
66C2CF23     | 8D55 9C           | lea edx,dword ptr ss:[ebp-64]        |
66C2CF26     | 8D8D 44FFFFFF     | lea ecx,dword ptr ss:[ebp-BC]        |
66C2CF2C     | E8 AF0D4700       | call wechatwin.6709DCE0              |
66C2CF31     | 83EC 14           | sub esp,14                           |
66C2CF34     | 8D85 0CFFFFFF     | lea eax,dword ptr ss:[ebp-F4]        |
66C2CF3A     | 8BCC              | mov ecx,esp                          |
66C2CF3C     | 8965 B0           | mov dword ptr ss:[ebp-50],esp        |
66C2CF3F     | 50                | push eax                             |
66C2CF40     | E8 9BFA4700       | call wechatwin.670AC9E0              |
66C2CF45     | 83EC 14           | sub esp,14                           |
66C2CF48     | 8BCC              | mov ecx,esp                          |
66C2CF4A     | 8965 8C           | mov dword ptr ss:[ebp-74],esp        |
66C2CF4D     | 6A FF             | push FFFFFFFF                        |
66C2CF4F     | 68 C8B92F68       | push wechatwin.682FB9C8              |
66C2CF54     | E8 47FA4700       | call wechatwin.670AC9A0              |
66C2CF59     | 83EC 14           | sub esp,14                           |
66C2CF5C     | 8D45 9C           | lea eax,dword ptr ss:[ebp-64]        |
66C2CF5F     | 8BCC              | mov ecx,esp                          |
66C2CF61     | 8965 90           | mov dword ptr ss:[ebp-70],esp        |
66C2CF64     | 50                | push eax                             |
66C2CF65     | E8 76FA4700       | call wechatwin.670AC9E0              |
66C2CF6A     | 83EC 14           | sub esp,14                           |
66C2CF6D     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
66C2CF73     | 8BCC              | mov ecx,esp                          |
66C2CF75     | 8965 BC           | mov dword ptr ss:[ebp-44],esp        |
66C2CF78     | 50                | push eax                             |
66C2CF79     | E8 62FA4700       | call wechatwin.670AC9E0              |
66C2CF7E     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CF84     | C645 FC 1D        | mov byte ptr ss:[ebp-4],1D           |
66C2CF88     | 50                | push eax                             |
66C2CF89     | E8 B2BAF5FF       | call wechatwin.66B88A40              |
66C2CF8E     | 8BC8              | mov ecx,eax                          |
66C2CF90     | C645 FC 19        | mov byte ptr ss:[ebp-4],19           |
66C2CF94     | E8 B74A1B00       | call wechatwin.66DE1A50              |
66C2CF99     | C645 FC 1E        | mov byte ptr ss:[ebp-4],1E           |
66C2CF9D     | E8 DEE61D00       | call wechatwin.66E0B680              |
66C2CFA2     | 8BC8              | mov ecx,eax                          |
66C2CFA4     | E8 87A23F00       | call wechatwin.67027230              |
66C2CFA9     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CFAF     | 8955 BC           | mov dword ptr ss:[ebp-44],edx        |
66C2CFB2     | 8BF8              | mov edi,eax                          |
66C2CFB4     | E8 77A23F00       | call wechatwin.67027230              |
66C2CFB9     | 3BC7              | cmp eax,edi                          |
66C2CFBB     | 75 05             | jne wechatwin.66C2CFC2               |
66C2CFBD     | 3B55 BC           | cmp edx,dword ptr ss:[ebp-44]        |
66C2CFC0     | 74 35             | je wechatwin.66C2CFF7                |
66C2CFC2     | 8B7D B4           | mov edi,dword ptr ss:[ebp-4C]        |
66C2CFC5     | 8BCF              | mov ecx,edi                          |
66C2CFC7     | E8 24220000       | call wechatwin.66C2F1F0              |
66C2CFCC     | 84C0              | test al,al                           |
66C2CFCE     | 74 27             | je wechatwin.66C2CFF7                |
66C2CFD0     | 8D45 0C           | lea eax,dword ptr ss:[ebp+C]         |
66C2CFD3     | 50                | push eax                             |
66C2CFD4     | 8D4F 18           | lea ecx,dword ptr ds:[edi+18]        | [edi+18]:"牨說%"
66C2CFD7     | E8 74014800       | call wechatwin.670AD150              |
66C2CFDC     | 84C0              | test al,al                           |
66C2CFDE     | 74 17             | je wechatwin.66C2CFF7                |
66C2CFE0     | 6A 01             | push 1                               |
66C2CFE2     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2CFE8     | 8BCF              | mov ecx,edi                          |
66C2CFEA     | 50                | push eax                             |
66C2CFEB     | 8D85 34FFFFFF     | lea eax,dword ptr ss:[ebp-CC]        |
66C2CFF1     | 50                | push eax                             |
66C2CFF2     | E8 290B0000       | call wechatwin.66C2DB20              |
66C2CFF7     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2CFFD     | E8 7E0AF5FF       | call wechatwin.66B7DA80              |
66C2D002     | 8D4D 9C           | lea ecx,dword ptr ss:[ebp-64]        |
66C2D005     | E8 46FC4700       | call wechatwin.670ACC50              |
66C2D00A     | 8D8D 20FFFFFF     | lea ecx,dword ptr ss:[ebp-E0]        |
66C2D010     | E8 3BFC4700       | call wechatwin.670ACC50              |
66C2D015     | 8D8D 0CFFFFFF     | lea ecx,dword ptr ss:[ebp-F4]        |
66C2D01B     | E8 30FC4700       | call wechatwin.670ACC50              |
66C2D020     | 8D8D 44FFFFFF     | lea ecx,dword ptr ss:[ebp-BC]        |
66C2D026     | E8 25FC4700       | call wechatwin.670ACC50              |
66C2D02B     | E9 04010000       | jmp wechatwin.66C2D134               |
66C2D030     | C785 60FFFFFF 000 | mov dword ptr ss:[ebp-A0],0          |
66C2D03A     | C785 64FFFFFF 000 | mov dword ptr ss:[ebp-9C],0          |
66C2D044     | C785 68FFFFFF 000 | mov dword ptr ss:[ebp-98],0          |
66C2D04E     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2D054     | C645 FC 1F        | mov byte ptr ss:[ebp-4],1F           |
66C2D058     | E8 9313F5FF       | call wechatwin.66B7E3F0              |
66C2D05D     | 8D8D F0EFFFFF     | lea ecx,dword ptr ss:[ebp-1010]      |
66C2D063     | C645 FC 20        | mov byte ptr ss:[ebp-4],20           | 20:' '
66C2D067     | E8 84BBF9FF       | call wechatwin.66BC8BF0              |
66C2D06C     | 8D85 F0EFFFFF     | lea eax,dword ptr ss:[ebp-1010]      |
66C2D072     | 50                | push eax                             |
66C2D073     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
66C2D079     | 50                | push eax                             |
66C2D07A     | 8D85 60FFFFFF     | lea eax,dword ptr ss:[ebp-A0]        |
66C2D080     | 50                | push eax                             |
66C2D081     | 83EC 14           | sub esp,14                           |
66C2D084     | 8BCC              | mov ecx,esp                          |
66C2D086     | 8965 B0           | mov dword ptr ss:[ebp-50],esp        |
66C2D089     | 53                | push ebx                             |
66C2D08A     | E8 51F94700       | call wechatwin.670AC9E0              |
66C2D08F     | C645 FC 22        | mov byte ptr ss:[ebp-4],22           | 22:'\"'
66C2D093     | E8 F857FAFF       | call wechatwin.66BD2890              |
66C2D098     | C645 FC 21        | mov byte ptr ss:[ebp-4],21           | 21:'!'
66C2D09C     | E8 9F3F2700       | call wechatwin.66EA1040              |
66C2D0A1     | 84C0              | test al,al                           |
66C2D0A3     | 74 6E             | je wechatwin.66C2D113                |
66C2D0A5     | C785 6CFFFFFF 000 | mov dword ptr ss:[ebp-94],0          |
66C2D0AF     | C785 70FFFFFF 000 | mov dword ptr ss:[ebp-90],0          |
66C2D0B9     | C785 74FFFFFF 000 | mov dword ptr ss:[ebp-8C],0          |
66C2D0C3     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
66C2D0C9     | C645 FC 23        | mov byte ptr ss:[ebp-4],23           | 23:'#'
66C2D0CD     | 50                | push eax                             |
66C2D0CE     | 8D8D 6CFFFFFF     | lea ecx,dword ptr ss:[ebp-94]        |
66C2D0D4     | E8 5754F7FF       | call wechatwin.66BA2530              |
66C2D0D9     | 83EC 0C           | sub esp,C                            |
66C2D0DC     | 8D85 6CFFFFFF     | lea eax,dword ptr ss:[ebp-94]        |
66C2D0E2     | 8BCC              | mov ecx,esp                          |
66C2D0E4     | 8965 B0           | mov dword ptr ss:[ebp-50],esp        |
66C2D0E7     | 50                | push eax                             |
66C2D0E8     | E8 2395F5FF       | call wechatwin.66B86610              |
66C2D0ED     | 8D85 60FFFFFF     | lea eax,dword ptr ss:[ebp-A0]        |
66C2D0F3     | C645 FC 24        | mov byte ptr ss:[ebp-4],24           | 24:'$'
66C2D0F7     | 50                | push eax                             |
66C2D0F8     | E8 9357FAFF       | call wechatwin.66BD2890              |
66C2D0FD     | 8BC8              | mov ecx,eax                          |
66C2D0FF     | C645 FC 23        | mov byte ptr ss:[ebp-4],23           | 23:'#'
66C2D103     | E8 A84B2700       | call wechatwin.66EA1CB0              |
66C2D108     | 8D8D 6CFFFFFF     | lea ecx,dword ptr ss:[ebp-94]        |
66C2D10E     | E8 FD08F5FF       | call wechatwin.66B7DA10              |
66C2D113     | 8D8D F0EFFFFF     | lea ecx,dword ptr ss:[ebp-1010]      |
66C2D119     | E8 92A9F9FF       | call wechatwin.66BC7AB0              |
66C2D11E     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
66C2D124     | E8 5709F5FF       | call wechatwin.66B7DA80              |
66C2D129     | 8D8D 60FFFFFF     | lea ecx,dword ptr ss:[ebp-A0]        |
66C2D12F     | E8 CC9CF6FF       | call wechatwin.66B96E00              |
66C2D134     | 8D8D 78FFFFFF     | lea ecx,dword ptr ss:[ebp-88]        |
66C2D13A     | C645 FC 00        | mov byte ptr ss:[ebp-4],0            |
66C2D13E     | E8 0DFB4700       | call wechatwin.670ACC50              |
66C2D143     | 8B45 08           | mov eax,dword ptr ss:[ebp+8]         |
66C2D146     | 83C6 48           | add esi,48                           |
66C2D149     | 83C3 48           | add ebx,48                           |
66C2D14C     | 3B70 04           | cmp esi,dword ptr ds:[eax+4]         |
66C2D14F     | 74 08             | je wechatwin.66C2D159                |
66C2D151     | 8B7D 10           | mov edi,dword ptr ss:[ebp+10]        |
66C2D154     | E9 87F7FFFF       | jmp wechatwin.66C2C8E0               |
66C2D159     | 8B5D B4           | mov ebx,dword ptr ss:[ebp-4C]        |
66C2D15C     | 8B8B 68040000     | mov ecx,dword ptr ds:[ebx+468]       |
66C2D162     | 85C9              | test ecx,ecx                         |
66C2D164     | 74 0B             | je wechatwin.66C2D171                |
66C2D166     | 8B01              | mov eax,dword ptr ds:[ecx]           |
66C2D168     | 8B40 24           | mov eax,dword ptr ds:[eax+24]        |
66C2D16B     | FFD0              | call eax                             |
66C2D16D     | 84C0              | test al,al                           |
66C2D16F     | 74 38             | je wechatwin.66C2D1A9                |
66C2D171     | 8B45 0C           | mov eax,dword ptr ss:[ebp+C]         |
66C2D174     | 85C0              | test eax,eax                         |
66C2D176     | 74 06             | je wechatwin.66C2D17E                |
66C2D178     | 66:8338 00        | cmp word ptr ds:[eax],0              |
66C2D17C     | 75 05             | jne wechatwin.66C2D183               |
66C2D17E     | B8 C8B92F68       | mov eax,wechatwin.682FB9C8           |
66C2D183     | 50                | push eax                             |
66C2D184     | 8D4B 18           | lea ecx,dword ptr ds:[ebx+18]        |
66C2D187     | E8 94004800       | call wechatwin.670AD220              |
66C2D18C     | 85C0              | test eax,eax                         |
66C2D18E     | 75 19             | jne wechatwin.66C2D1A9               |
66C2D190     | 8BCB              | mov ecx,ebx                          |
66C2D192     | E8 C9F4FFFF       | call wechatwin.66C2C660              |
66C2D197     | 6A 00             | push 0                               |
66C2D199     | 6A 00             | push 0                               |
66C2D19B     | 6A 00             | push 0                               |
66C2D19D     | 6A 00             | push 0                               |
66C2D19F     | 6A 01             | push 1                               |
66C2D1A1     | 8D4B 08           | lea ecx,dword ptr ds:[ebx+8]         |
66C2D1A4     | E8 67A8F9FF       | call wechatwin.66BC7A10              |
66C2D1A9     | B3 01             | mov bl,1                             |
66C2D1AB     | 8D4D 0C           | lea ecx,dword ptr ss:[ebp+C]         |
66C2D1AE     | E8 9DFA4700       | call wechatwin.670ACC50              |
66C2D1B3     | 8AC3              | mov al,bl                            |
66C2D1B5     | 8B4D F4           | mov ecx,dword ptr ss:[ebp-C]         |
66C2D1B8     | 64:890D 00000000  | mov dword ptr fs:[0],ecx             |
66C2D1BF     | 59                | pop ecx                              |
66C2D1C0     | 5F                | pop edi                              |
66C2D1C1     | 5E                | pop esi                              |
66C2D1C2     | 5B                | pop ebx                              |
66C2D1C3     | 8B4D F0           | mov ecx,dword ptr ss:[ebp-10]        |
66C2D1C6     | 33CD              | xor ecx,ebp                          |
66C2D1C8     | E8 AF6CF400       | call wechatwin.67B73E7C              |
66C2D1CD     | 8BE5              | mov esp,ebp                          |
66C2D1CF     | 5D                | pop ebp                              |
66C2D1D0     | C2 1800           | ret 18                               |
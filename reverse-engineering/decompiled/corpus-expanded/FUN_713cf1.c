/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x713cf1; label: xtoa_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _xtoa_s@20
   
   Library: Visual Studio 2005 Release
   __stdcall xtoa_s,20 */

undefined4 xtoa_s(uint param_1,uint param_2,int param_3)

{
  ulonglong uVar1;
  char *pcVar2;
  uint in_EAX;
  undefined4 *puVar3;
  char *in_ECX;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  undefined4 uVar7;
  uint local_8;
  
  if (in_ECX == (char *)0x0) {
    puVar3 = (undefined4 *)FUN_006ead5f();
    *puVar3 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return 0x16;
  }
  if (param_1 == 0) {
LAB_00713d23:
    puVar3 = (undefined4 *)FUN_006ead5f();
    uVar7 = 0x16;
  }
  else {
    *in_ECX = '\0';
    if ((param_3 != 0) + 1 < param_1) {
      if (0x22 < param_2 - 2) goto LAB_00713d23;
      pcVar6 = in_ECX;
      if (param_3 != 0) {
        *in_ECX = '-';
        pcVar6 = in_ECX + 1;
        in_EAX = -in_EAX;
      }
      local_8 = (uint)(param_3 != 0);
      pcVar2 = pcVar6;
      do {
        pcVar4 = pcVar2;
        uVar1 = (ulonglong)in_EAX;
        in_EAX = in_EAX / param_2;
        cVar5 = (char)(uVar1 % (ulonglong)param_2);
        if ((uint)(uVar1 % (ulonglong)param_2) < 10) {
          cVar5 = cVar5 + '0';
        }
        else {
          cVar5 = cVar5 + 'W';
        }
        *pcVar4 = cVar5;
        local_8 = local_8 + 1;
      } while ((in_EAX != 0) && (pcVar2 = pcVar4 + 1, local_8 < param_1));
      if (local_8 < param_1) {
        pcVar4[1] = '\0';
        do {
          cVar5 = *pcVar4;
          *pcVar4 = *pcVar6;
          pcVar4 = pcVar4 + -1;
          *pcVar6 = cVar5;
          pcVar6 = pcVar6 + 1;
        } while (pcVar6 < pcVar4);
        return 0;
      }
      *in_ECX = '\0';
    }
    puVar3 = (undefined4 *)FUN_006ead5f();
    uVar7 = 0x22;
  }
  *puVar3 = uVar7;
  FUN_006e9fc2(0,0,0,0,0);
  return uVar7;
}


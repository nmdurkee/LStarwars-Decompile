/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x71373a; label: cvtdate
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _cvtdate
   
   Library: Visual Studio 2005 Release */

int __cdecl
cvtdate(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
       int param_8,int param_9)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  errno_t eVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  long local_8;
  
  local_8 = 0;
  if (param_2 == 1) {
    uVar1 = param_3 & 0x80000003;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;
    }
    if (((uVar1 == 0) && ((int)param_3 % 100 != 0)) || ((int)(param_3 + 0x76c) % 400 == 0)) {
      iVar5 = *(int *)(&DAT_0082adf0 + in_EAX * 4);
    }
    else {
      iVar5 = *(int *)(&DAT_0082ae24 + in_EAX * 4);
    }
    iVar6 = iVar5 + 1;
    iVar4 = (int)(param_3 * 0x16d + -0x63db +
                 ((int)((param_3 - 1) + ((int)(param_3 - 1) >> 0x1f & 3U)) >> 2) + iVar6 +
                 ((int)(param_3 + 299) / 400 - (int)(param_3 - 1) / 100)) % 7;
    iVar2 = (param_4 * 7 - iVar4) + param_5;
    if (iVar4 <= param_5) {
      iVar6 = iVar5 + -6;
    }
    iVar6 = iVar6 + iVar2;
    if (param_4 == 5) {
      if (((uVar1 == 0) && ((int)param_3 % 100 != 0)) || ((int)(param_3 + 0x76c) % 400 == 0)) {
        iVar2 = *(int *)(&DAT_0082adf4 + in_EAX * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_0082ae28 + in_EAX * 4);
      }
      if (iVar2 < iVar6) {
        iVar6 = iVar6 + -7;
      }
    }
  }
  else {
    uVar1 = param_3 & 0x80000003;
    bVar7 = uVar1 == 0;
    if ((int)uVar1 < 0) {
      bVar7 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if (((bVar7) && (iVar2 = (int)param_3 / 100, (int)param_3 % 100 != 0)) ||
       (iVar2 = (int)(param_3 + 0x76c) / 400, (int)(param_3 + 0x76c) % 400 == 0)) {
      iVar6 = *(int *)(&DAT_0082adf0 + in_EAX * 4);
    }
    else {
      iVar6 = *(int *)(&DAT_0082ae24 + in_EAX * 4);
    }
    iVar6 = iVar6 + param_6;
  }
  param_9 = ((in_ECX * 0x3c + param_7) * 0x3c + param_8) * 1000 + param_9;
  if (param_1 == 1) {
    DAT_0082ab20 = param_3;
    DAT_0082ab24 = iVar6;
    DAT_0082ab28 = param_9;
  }
  else {
    DAT_0082ab30 = iVar6;
    DAT_0082ab34 = param_9;
    eVar3 = __get_dstbias(&local_8);
    if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    iVar2 = local_8 * 1000;
    DAT_0082ab34 = DAT_0082ab34 + iVar2;
    if (DAT_0082ab34 < 0) {
      DAT_0082ab34 = DAT_0082ab34 + 86400000;
      DAT_0082ab30 = DAT_0082ab30 + -1;
    }
    else {
      iVar2 = 86400000;
      if (86399999 < DAT_0082ab34) {
        DAT_0082ab34 = DAT_0082ab34 + -86400000;
        DAT_0082ab30 = DAT_0082ab30 + 1;
      }
    }
    DAT_0082ab2c = param_3;
  }
  return iVar2;
}


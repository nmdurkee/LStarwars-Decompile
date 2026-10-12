/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745410; label: FUN_00745410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745410(uint *param_1,int param_2)

{
  int in_ECX;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1[0x4f] & 0x4000000) != 0) {
    param_1[0x6e] = param_1[0x6e] | 0x80000000;
    *param_1 = *param_1 | 0x200000;
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0x7918c) + 0xb80);
  if (DAT_008264c7 == '\0') {
    iVar1 = 1;
  }
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      *param_1 = *param_1 & 0xff7efffb;
      param_1[0x6e] = param_1[0x6e] & 0xbffbfffb;
      if ((*param_1 & 0x20) != 0) {
        *param_1 = *param_1 & 0xfffffff7;
        param_1[0x6e] = param_1[0x6e] & 0xfffffff7;
      }
      if ((*param_1 & 0x20) != 0) {
        param_1[0x6e] = param_1[0x6e] & 0xffff7fff;
        *param_1 = *param_1 & 0xfffdffff;
      }
      if ((*param_1 & 0x20) != 0) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffffc;
        *param_1 = *param_1 & 0xfffffffc;
      }
      if (((*param_1 & 0x20000) != 0) || ((param_1[0x6e] & 0x8000) != 0)) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffff7;
        *param_1 = *param_1 & 0xfffffff7;
      }
      if ((*param_1 & 3) != 0) {
        param_1[0x6e] = param_1[0x6e] & 0xfdffffef;
        *param_1 = *param_1 & 0xbfffffef;
      }
      if ((*param_1 & 2) != 0) {
        *param_1 = *param_1 & 0xfffffffd | 1;
        param_1[0x6e] = param_1[0x6e] & 0xfffffffd | 1;
      }
      if (((byte)*param_1 & 0x60) == 0x60) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffffe;
        *param_1 = *param_1 & 0xfffffffe;
      }
      if ((char)*param_1 < '\0') {
        param_1[0x6e] = param_1[0x6e] & 0xfffffffe;
        *param_1 = *param_1 & 0xfffffffe;
      }
      if (((byte)*param_1 & 0x25) == 0x25) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffffe;
        *param_1 = *param_1 & 0xfffffffe;
      }
      if (((*param_1 & 1) != 0) && (param_1[0xe] != 0)) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffffe;
        *param_1 = *param_1 & 0xfffffffe;
      }
      param_1[0x6e] = param_1[0x6e] & 0xffff9bff;
      *param_1 = *param_1 & 0xffff9bff;
      uVar2 = param_1[0x6e];
      if (((((uVar2 & 0x4000000) != 0) && ((uVar2 & 8) != 0)) && ((int)uVar2 < 0)) &&
         ((uVar2 & 1) != 0)) {
        *param_1 = *param_1 & 0xfffffff7;
        param_1[0x6e] = uVar2 & 0xfffffff7;
      }
      *param_1 = *param_1 & 0xfdffffef;
      param_1[0x6e] = param_1[0x6e] & 0xffefffef;
      if (((byte)*param_1 & 0x49) == 0x49) {
        *param_1 = *param_1 & 0xfffffffe;
        param_1[0x6e] = param_1[0x6e] & 0xfffffffe;
      }
      uVar2 = *param_1;
      if (((uVar2 & 0x100) != 0) && ((uVar2 & 8) != 0)) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffff7;
        *param_1 = uVar2 & 0xfffffff7;
      }
      if ((*param_1 & 0x80201000) == 0x80201000) {
        param_1[0x6e] = param_1[0x6e] & 0xfffffff6;
        *param_1 = *param_1 & 0xfffffff6;
      }
      *param_1 = *param_1 & 0xfff7ffff;
      param_1[0x6e] = param_1[0x6e] & 0xe7feffff;
    }
    else if (iVar1 == 3) {
      *param_1 = *param_1 & 0xff77dffb;
      param_1[0x6e] = param_1[0x6e] & 0xe7fadffb;
    }
    goto LAB_0074572f;
  }
  uVar2 = param_1[0x6e];
  if ((*param_1 & 0x40200) == 0) {
    *param_1 = *param_1 & 0xfffffbff;
  }
  param_1[0x6e] = uVar2 & 0xfffffbff;
  if (((uVar2 >> 10 & 1) != 0) && ((*(uint *)(param_2 + 0x40) & 0x700000) != 0x100000)) {
    *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) & 0x807fffff;
  }
  uVar2 = *param_1;
  if ((uVar2 & 0x4000) != 0) {
    param_1[0x22] = (uint)((float)param_1[0x22] * 0.4);
  }
  param_1[0x6e] = param_1[0x6e] & 0xffff9ffc;
  *param_1 = uVar2 & 0xffff9ffc;
  if ((uVar2 & 0x10000) == 0) {
    if ((uVar2 & 0x20) != 0) {
      uVar2 = uVar2 & 0xffff9ff4;
      uVar3 = param_1[0x6e] & 0xfffffff7;
      goto LAB_007456e6;
    }
  }
  else {
    uVar2 = uVar2 & 0xffff9fdc;
    uVar3 = param_1[0x6e] & 0xffffffdf;
LAB_007456e6:
    param_1[0x6e] = uVar3;
    *param_1 = uVar2;
  }
  if ((*param_1 & 3) != 0) {
    param_1[0x6e] = param_1[0x6e] & 0xfffffff7;
    *param_1 = *param_1 & 0xfffffff7;
  }
  param_1[0x6e] = param_1[0x6e] & 0x27c8fffb;
  *param_1 = *param_1 & 0xf916fffb;
  if ((param_1[0x6e] & 0x4000000) != 0) {
    *param_1 = *param_1 & 0xffffffd7;
    param_1[0x6e] = param_1[0x6e] & 0xffffffd7;
  }
LAB_0074572f:
  if (*(char *)(*(int *)(in_ECX + 0x7918c) + 0xb7c) != '\0') {
    *param_1 = *param_1 & 0xfffffbd7;
    param_1[0x6e] = param_1[0x6e] & 0xfffffbd7;
  }
  return;
}


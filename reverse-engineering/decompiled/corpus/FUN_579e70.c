/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x579e70; label: FUN_00579e70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00579e70(char *param_1,uint *param_2,uint *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = -1;
  iVar5 = -1;
  iVar4 = -1;
  iVar3 = -1;
  DAT_00803b78 = -1;
  DAT_00803b7c = -1;
  DAT_00803b80 = -1;
  _DAT_00803b84 = -1;
  DAT_00951bb8 = param_1;
  DAT_00951bb4 = 0;
  cVar1 = *param_1;
  DAT_00951bc0 = param_4;
  while (cVar1 != -1) {
    if ((*(short *)(param_1 + 2) == 1) &&
       (iVar5 = DAT_00951bbc, DAT_00803b7c = DAT_00951bbc, iVar6 == -1)) {
      iVar6 = DAT_00951bbc;
      DAT_00803b78 = DAT_00951bbc;
    }
    if ((*(short *)(param_1 + 2) == 2) &&
       (iVar3 = DAT_00951bbc, _DAT_00803b84 = DAT_00951bbc, iVar4 == -1)) {
      iVar4 = DAT_00951bbc;
      DAT_00803b80 = DAT_00951bbc;
    }
    DAT_00951bbc = DAT_00951bbc + 1;
    param_1 = param_1 + 8;
    cVar1 = *param_1;
  }
  iVar5 = iVar5 - iVar6;
  iVar3 = iVar3 - iVar4;
  if (iVar3 < iVar5) {
    DAT_00803b7c = iVar6 + iVar3;
  }
  else if (iVar5 < iVar3) {
    _DAT_00803b84 = iVar4 + iVar5;
  }
  if (0 < param_5) {
    DAT_00951bc8 = *param_2;
    uVar2 = DAT_00951bc8 + param_5;
    *param_2 = uVar2;
    DAT_00951bcc = param_5;
    if (*param_3 <= uVar2) {
      FUN_00578890(param_5);
    }
  }
  return;
}


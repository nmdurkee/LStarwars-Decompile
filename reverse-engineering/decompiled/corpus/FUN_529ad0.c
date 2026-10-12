/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x529ad0; label: FUN_00529ad0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00529ad0(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_004f8b10(param_1,&DAT_00921f20);
  if (iVar2 != 0) {
    iVar2 = (int)&DAT_00921f20 - (int)param_1;
    do {
      cVar1 = *param_1;
      param_1[iVar2] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
  }
  if (param_2 != 0) {
    DAT_00921f3c = *(undefined4 *)(param_2 + 0x70);
    DAT_00921f40 = *(undefined4 *)(param_2 + 0x74);
    _DAT_00921f44 = *(undefined4 *)(param_2 + 0x78);
    _DAT_00921f48 = *(undefined4 *)(param_2 + 0x7c);
    DAT_00921f4c = *(uint *)(param_2 + 0x68) & 0x1e;
    return;
  }
  iVar2 = FUN_00513010(*(undefined4 *)(DAT_009238e4 + 100),&DAT_00921f20,1,1,1);
  if (iVar2 != 0) {
    DAT_00921f3c = *(undefined4 *)(iVar2 + 0x1c);
    DAT_00921f40 = *(undefined4 *)(iVar2 + 0x24);
    _DAT_00921f44 = *(undefined4 *)(iVar2 + 0x2c);
    DAT_00921f4c = 0;
    _DAT_00921f48 = *(undefined4 *)(iVar2 + 0x34);
    return;
  }
  DAT_00921f4c = 0;
  DAT_00921f3c = 0;
  DAT_00921f40 = 0;
  _DAT_00921f44 = 0;
  _DAT_00921f48 = 0;
  return;
}


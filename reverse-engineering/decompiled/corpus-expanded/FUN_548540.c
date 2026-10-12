/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548540; label: FUN_00548540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548540(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 0;
  if ((*(byte *)(param_2 + 0x280) != 0xff) ||
     (*(char *)((int)*(short *)(param_2 + 0x106a) + *(int *)(PTR_DAT_00802c54 + 0x2a94)) != '\0')) {
    if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
      iVar2 = 1 << (*(byte *)(param_2 + 0x280) & 0x1f);
    }
    if (param_1 != 0) {
      uVar3 = FUN_00650dc0(param_1);
      if (param_3 == 0) {
        param_3 = param_2 + 0x80;
      }
      FUN_00681e90(uVar3,param_3);
      return;
    }
    sVar1 = *(short *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0xea);
    if (sVar1 != -1) {
      FUN_005478a0((int)sVar1,param_2 + 0x80,iVar2,1);
      return;
    }
    FUN_00681e90((int)*(short *)(PTR_DAT_008020bc + 0x1d8),param_2 + 0x80);
  }
  return;
}


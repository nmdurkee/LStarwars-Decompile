/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5b0550; label: FUN_005b0550
 */

undefined4 FUN_005b0550(undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_0055f460();
  if (((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 0x50f8), iVar1 != 0)) &&
     (uVar2 = *(uint *)(iVar3 + 0x50fc), uVar2 != *(byte *)(*(int *)(iVar3 + 0x128) + 0xe9))) {
    *(undefined4 *)(iVar1 + 4 + uVar2 * 0x1c) = param_2;
    iVar1 = iVar1 + uVar2 * 0x1c;
    *(byte *)(iVar1 + 10) = *(byte *)(iVar1 + 10) ^ (param_3 * '\x02' ^ *(byte *)(iVar1 + 10)) & 2;
    FUN_004f1f40(iVar1 + 0xc,param_4,0x10);
    *(int *)(iVar3 + 0x50fc) = *(int *)(iVar3 + 0x50fc) + 1;
    uVar4 = FUN_00559ee0(*(undefined4 *)(iVar3 + 0x2ac8),DAT_008061b8,0,iVar1);
    return uVar4;
  }
  return 0;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x546fd0; label: FUN_00546fd0
 */

int FUN_00546fd0(uint *param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
                undefined2 param_6,uint param_7)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = FUN_005f8d60(param_3,param_1,param_2);
  *param_1 = *param_1 + 0xf & 0xfffffff0;
  iVar2 = FUN_005e4d40(1);
  *(undefined4 *)(iVar2 + 0x54) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x58) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x70) = 0x3f7fbe77;
  *(uint *)(iVar2 + 0x40) =
       (param_7 & 3) << 0xe | *(uint *)(iVar2 + 0x40) & 0xfffe2ff0 | param_5 & 0xf | 0x22000;
  if (param_4 != 0) {
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 4;
  }
  *(undefined2 *)(iVar2 + 0x74) = uVar1;
  *(undefined2 *)(iVar2 + 0x76) = param_6;
  FUN_005e4b00(iVar2);
  return iVar2;
}


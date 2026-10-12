/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0aa0; label: FUN_005d0aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d0aa0(int param_1,int param_2,ushort param_3)

{
  ushort uVar1;
  int iVar2;
  undefined2 uVar4;
  int iVar3;
  int iVar5;
  
  iVar2 = param_2 / 2;
  if (*(ushort *)(param_1 + -4 + param_2 * 4) < param_3) {
    return CONCAT22((short)((uint)iVar2 >> 0x10),0xffff);
  }
  param_2 = param_2 + -1;
  uVar1 = *(ushort *)(param_1 + iVar2 * 4);
  iVar5 = 0;
  while( true ) {
    uVar4 = (undefined2)((uint)iVar2 >> 0x10);
    if (uVar1 == param_3) {
      return CONCAT22(uVar4,*(undefined2 *)(param_1 + 2 + iVar2 * 4));
    }
    if (param_2 == iVar5 + 1) break;
    if (param_3 < uVar1) {
      iVar3 = iVar2 + iVar5 >> 1;
      param_2 = iVar2;
    }
    else if (uVar1 < param_3) {
      iVar3 = iVar2 + param_2 >> 1;
      iVar5 = iVar2;
    }
    else {
      iVar3 = iVar2;
      if (param_2 == iVar5) goto LAB_005d0b29;
    }
    uVar1 = *(ushort *)(param_1 + iVar3 * 4);
    iVar2 = iVar3;
  }
  if (*(ushort *)(param_1 + param_2 * 4) == param_3) {
    return CONCAT22(uVar4,*(undefined2 *)(param_1 + 2 + param_2 * 4));
  }
  if (*(ushort *)(param_1 + iVar5 * 4) == param_3) {
    return CONCAT22(uVar4,*(undefined2 *)(param_1 + 2 + iVar5 * 4));
  }
LAB_005d0b29:
  return CONCAT22(uVar4,0xffff);
}


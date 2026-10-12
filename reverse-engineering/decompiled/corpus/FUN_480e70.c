/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x480e70; label: FUN_00480e70
 */

undefined4 FUN_00480e70(int param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = *param_2;
  bVar1 = *(byte *)(param_1 + 0x160);
  iVar4 = *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
  iVar3 = *(int *)(param_1 + 0x15c);
  iVar5 = (uint)*(byte *)((bVar1 == 0) + 0x10 + iVar3) * 0x5c + iVar4;
  if ((*(byte *)(iVar3 + (uint)bVar1 * 4) & 0x80) == 0) {
    iVar4 = FUN_0043c9a0(uVar2,iVar5,0);
    if (iVar4 == 0) {
      FUN_00561e20(uVar2,iVar5 + 4,0,0x3f000000,0x3f800000,0);
      FUN_0043cbb0(uVar2,iVar5,0,2);
      return 0;
    }
  }
  else {
    iVar5 = (uint)*(byte *)(bVar1 + 0x10 + iVar3) * 0x5c;
    iVar3 = iVar5 + 4 + iVar4;
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar5 + 4 + iVar4);
    *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(iVar3 + 4);
    uVar2 = *(undefined4 *)(iVar3 + 8);
    *(uint *)(param_1 + 0x1e8) = *(uint *)(param_1 + 0x1e8) | 0x800000;
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x10c) = uVar2;
    *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  }
  return 1;
}


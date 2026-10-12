/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d47a0; label: FUN_006d47a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d47a0(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  *(undefined1 *)(param_2 + 0x1b) = 0;
  *(undefined2 *)(param_2 + 0x18) = 0;
  *(undefined1 *)(param_2 + 0x1a) = 5;
  if ((*(undefined **)(param_2 + 8) != &DAT_028e045e) &&
     (*(undefined **)(param_2 + 8) != (undefined *)0x719045e)) {
    *(uint *)(param_2 + 0x20) = (uint)*(ushort *)(param_1 + 0x10);
    *(uint *)(param_2 + 0x24) = (uint)*(ushort *)(param_1 + 0x12);
    iVar3 = 2;
    do {
      bVar2 = (byte)iVar3;
      if (((uint)*(ushort *)(param_1 + 4) & 1 << (bVar2 - 2 & 0x1f)) != 0) {
        *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + 1;
      }
      if (((uint)*(ushort *)(param_1 + 4) & 1 << (bVar2 - 1 & 0x1f)) != 0) {
        *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + 1;
      }
      if (((uint)*(ushort *)(param_1 + 4) & 1 << (bVar2 & 0x1f)) != 0) {
        *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + 1;
      }
      if (((uint)*(ushort *)(param_1 + 4) & 1 << (bVar2 + 1 & 0x1f)) != 0) {
        *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + 1;
      }
      iVar1 = iVar3 + 2;
      iVar3 = iVar3 + 4;
    } while (iVar1 < 0x20);
    if ((*(byte *)(param_1 + 4) & 0xf) == 0xf) {
      *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + -4;
      *(undefined1 *)(param_2 + 0x1b) = 1;
    }
    return;
  }
  *(undefined2 *)(param_2 + 0x18) = 10;
  *(undefined1 *)(param_2 + 0x1b) = 1;
  *(undefined4 *)(param_2 + 0x20) = 0xffff;
  *(undefined4 *)(param_2 + 0x24) = 0xffff;
  return;
}


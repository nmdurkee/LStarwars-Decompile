/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51b7f0; label: FUN_0051b7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051b7f0(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  
  bVar1 = *(byte *)(*(int *)(param_1 + 0x158) + 0x14);
  if (((bVar1 != 0) && (*(int *)(param_1 + 0x15c) != 0)) &&
     (uVar2 = *(ushort *)(*(int *)(param_1 + 0x15c) + 0x14) & *(ushort *)(param_1 + 0x13a),
     uVar2 != 0)) {
    uVar4 = (uint)*(byte *)(param_1 + 0x13d);
    uVar5 = uVar4;
    if (bVar1 <= uVar4) {
      uVar4 = 0;
      uVar5 = uVar4;
    }
    while (uVar3 = __allshl(), (uVar3 & uVar2) == 0) {
      uVar4 = uVar4 + 1;
      if ((int)(uint)bVar1 <= (int)uVar4) {
        uVar4 = 0;
      }
      if (uVar4 == uVar5) {
        return;
      }
    }
    *(char *)(param_1 + 0x13c) = (char)uVar4;
    *(char *)(param_1 + 0x13d) = (char)uVar4 + '\x01';
  }
  return;
}


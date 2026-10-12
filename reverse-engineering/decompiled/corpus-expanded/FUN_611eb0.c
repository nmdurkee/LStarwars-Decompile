/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611eb0; label: FUN_00611eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611eb0(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_02900a3c == 0) {
    DAT_02900a3c = 1;
    uVar3 = 0;
    do {
      uVar2 = uVar3 >> 1;
      if ((uVar3 & 1) != 0) {
        uVar2 = uVar2 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar2 = uVar2 >> 1;
      }
      else {
        uVar2 = uVar2 >> 1 ^ 0xedb88320;
      }
      if ((uVar2 & 1) == 0) {
        uVar1 = (ushort)(uVar2 >> 1);
      }
      else {
        uVar1 = (ushort)(uVar2 >> 1) ^ 0x8320;
      }
      (&DAT_02900838)[uVar3] = uVar1;
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x100);
  }
  return;
}


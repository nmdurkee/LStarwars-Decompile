/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9140; label: FUN_005c9140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c9140(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    (&DAT_00971760)[uVar1] = 0;
    if ((uVar1 & 1) != 0) {
      (&DAT_00971760)[uVar1] = 1;
    }
    if ((uVar1 & 2) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 4) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 8) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 0x10) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 0x20) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 0x40) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((char)uVar1 < '\0') {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x100);
  DAT_00973868 = 1;
  return;
}


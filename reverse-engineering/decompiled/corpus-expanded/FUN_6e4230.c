/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e4230; label: FUN_006e4230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e4230(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x65c) = *(undefined1 *)(in_ECX + 0x66e);
  if (*(uint *)(in_ECX + 0x670) < *(uint *)(in_ECX + 0x618)) {
    *(uint *)(in_ECX + 0x660) = *(uint *)(in_ECX + 0x670);
  }
  else {
    *(undefined4 *)(in_ECX + 0x660) = *(undefined4 *)(in_ECX + 0x620);
  }
  *(undefined1 *)(in_ECX + 0x664) = *(undefined1 *)(in_ECX + 0x674);
  *(undefined2 *)(in_ECX + 0x66c) = *(undefined2 *)(in_ECX + 0x67c);
  *(undefined4 *)(in_ECX + 0x668) = *(undefined4 *)(in_ECX + 0x678);
  FUN_006daf70(*(undefined4 *)(in_ECX + 0x680));
  FUN_006db1c0();
  DAT_0297dbd0 = DAT_00826494;
  if (DAT_00826494 == 3) {
    DAT_0297dbd0 = *(int *)(in_ECX + 0x62c);
  }
  FUN_006e3940(1);
  return;
}


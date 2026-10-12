/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e4230; label: FUN_006e4230
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


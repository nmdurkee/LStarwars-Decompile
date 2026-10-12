/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659a30; label: FUN_00659a30
 */

void FUN_00659a30(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (param_2 < (&DAT_0292fe1c)[param_1 * 0xb5] + -1) {
    pcVar4 = &DAT_0292fe44 + param_1 * 0x2d4 + param_2 * 0x10;
    puVar3 = &DAT_0292ff14 + param_1 * 0xb5 + param_2 * 3;
    puVar2 = &DAT_0292feb4 + param_1 * 0xb5 + param_2;
    do {
      *puVar2 = puVar2[1];
      puVar2[8] = puVar2[9];
      puVar2[0x10] = puVar2[0x11];
      *puVar3 = puVar3[3];
      puVar3[1] = puVar3[4];
      puVar3[2] = puVar3[5];
      pcVar5 = pcVar4;
      do {
        cVar1 = *pcVar5;
        pcVar5[-0x10] = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 3;
      pcVar4 = pcVar4 + 0x10;
    } while (param_2 < (&DAT_0292fe1c)[param_1 * 0xb5] + -1);
  }
  (&DAT_0292fe1c)[param_1 * 0xb5] = (&DAT_0292fe1c)[param_1 * 0xb5] + -1;
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x659860; label: FUN_00659860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00659860(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  if (param_2 < (&DAT_0292fe20)[param_1 * 0xb5] + -1) {
    pcVar4 = &DAT_0292ffa8 + param_1 * 0x2d4 + param_2 * 0x10;
    puVar2 = (undefined4 *)(&DAT_02930078 + param_2 * 0xc + param_1 * 0x2d4);
    puVar5 = &DAT_02930018 + param_1 * 0xb5 + param_2;
    do {
      *puVar5 = puVar5[1];
      puVar5[0x10] = puVar5[0x11];
      *puVar2 = puVar2[3];
      puVar2[1] = puVar2[4];
      puVar2[2] = puVar2[5];
      pcVar3 = pcVar4;
      do {
        cVar1 = *pcVar3;
        pcVar3[-0x10] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 3;
      pcVar4 = pcVar4 + 0x10;
    } while (param_2 < (&DAT_0292fe20)[param_1 * 0xb5] + -1);
  }
  (&DAT_0292fe20)[param_1 * 0xb5] = (&DAT_0292fe20)[param_1 * 0xb5] + -1;
  return;
}


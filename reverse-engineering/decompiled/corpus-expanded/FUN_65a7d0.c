/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x65a7d0; label: FUN_0065a7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065a7d0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  
  iVar2 = DAT_0292fd08;
  iVar4 = DAT_02962010 * 0x2d4;
  DAT_029620e0 = 0;
  (&DAT_0292feb4)[DAT_02962010 * 0xb5 + DAT_0292fd08] = *(undefined4 *)(param_2 + 0xc);
  pcVar3 = *(char **)(DAT_0296209c + iVar2 * 4);
  pcVar5 = &DAT_0292fe34 + iVar2 * 0x10 + iVar4;
  do {
    cVar1 = *pcVar3;
    *pcVar5 = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  DAT_02924ac8 = *(undefined4 *)(param_2 + 0xc);
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x538820; label: FUN_00538820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00538820(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar2 = FUN_00617e20();
  iVar5 = 0;
  *(undefined4 *)(iVar2 + 0x48) = 0x3e19999a;
  if (0 < DAT_009220ec) {
    puVar6 = &DAT_00921f98;
    do {
      if ((code *)*puVar6 != (code *)0x0) {
        (*(code *)*puVar6)();
      }
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 0xc;
    } while (iVar5 < DAT_009220ec);
  }
  iVar2 = DAT_009238e4;
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    pcVar3 = (char *)(*(int *)(DAT_009238e4 + 0x371b0) + 8);
    pcVar4 = &DAT_00921f00;
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (*(int *)(iVar2 + 0x4868) != 0) {
    pcVar3 = (char *)(*(int *)(iVar2 + 0x4868) + 8);
    pcVar4 = &DAT_00921ef0;
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (*(int *)(iVar2 + 0x41208) != 0) {
    pcVar3 = (char *)(*(int *)(iVar2 + 0x41208) + 8);
    pcVar4 = &DAT_00921f10;
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  FUN_00537900();
  FUN_005143a0(*(undefined4 *)(DAT_009238e4 + 100));
  *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) & 0xfffffffd;
  return;
}


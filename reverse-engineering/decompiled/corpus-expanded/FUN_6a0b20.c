/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a0b20; label: FUN_006a0b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a0b20(int *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char local_20 [32];
  
  pcVar4 = "Xiph.Org libVorbis I 20070622";
  pcVar6 = local_20;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar6 = pcVar6 + 4;
  }
  pcVar2 = local_20;
  *(undefined2 *)pcVar6 = *(undefined2 *)pcVar4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = (int)pcVar2 - (int)(local_20 + 1);
  FUN_006a3570();
  iVar5 = 6;
  do {
    iVar5 = iVar5 + -1;
    FUN_006a3570();
  } while (iVar5 != 0);
  FUN_006a3570();
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    FUN_006a3570();
  }
  FUN_006a3570();
  if ((param_1[2] != 0) && (iVar3 = 0, 0 < param_1[2])) {
    do {
      if (*(int *)(*param_1 + iVar3 * 4) == 0) {
        FUN_006a3570();
      }
      else {
        FUN_006a3570();
        for (iVar5 = *(int *)(param_1[1] + iVar3 * 4); iVar5 != 0; iVar5 = iVar5 + -1) {
          FUN_006a3570();
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[2]);
  }
  FUN_006a3570();
  return 0;
}


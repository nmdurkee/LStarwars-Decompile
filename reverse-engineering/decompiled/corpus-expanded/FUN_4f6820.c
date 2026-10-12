/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6820; label: FUN_004f6820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_004f6820(undefined4 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  undefined *puVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar8 = DAT_0297e064;
  if (0xf < DAT_0297e064) {
    FUN_004ef790();
  }
  iVar7 = iVar8 * 0x234;
  puVar9 = &DAT_029803e0 + iVar8 * 0x8d;
  for (iVar6 = 0x8d; puVar3 = PTR_DAT_00800478, iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *param_1;
    param_1 = param_1 + 1;
    puVar9 = puVar9 + 1;
  }
  pcVar1 = PTR_DAT_00800478 + 0xac;
  pcVar2 = &DAT_0298048c + iVar7;
  pcVar4 = pcVar2;
  if ((pcVar1 != (char *)0x0) && (cVar5 = *pcVar1, cVar5 != '\0')) {
    do {
      *pcVar4 = cVar5;
      cVar5 = pcVar4[(int)(pcVar1 + (1 - (int)pcVar2))];
      pcVar4 = pcVar4 + 1;
    } while (cVar5 != '\0');
  }
  pcVar1 = puVar3 + 300;
  *pcVar4 = '\0';
  pcVar2 = &DAT_0298050c + iVar7;
  pcVar4 = pcVar2;
  if ((pcVar1 != (char *)0x0) && (cVar5 = *pcVar1, cVar5 != '\0')) {
    do {
      *pcVar4 = cVar5;
      cVar5 = pcVar4[(int)(pcVar1 + (1 - (int)pcVar2))];
      pcVar4 = pcVar4 + 1;
    } while (cVar5 != '\0');
  }
  pcVar1 = puVar3 + 0x1ac;
  *pcVar4 = '\0';
  pcVar2 = &DAT_0298058c + iVar7;
  pcVar4 = pcVar2;
  if ((pcVar1 != (char *)0x0) && (cVar5 = *pcVar1, cVar5 != '\0')) {
    do {
      *pcVar4 = cVar5;
      cVar5 = pcVar4[(int)(pcVar1 + (1 - (int)pcVar2))];
      pcVar4 = pcVar4 + 1;
    } while (cVar5 != '\0');
  }
  DAT_0297e064 = iVar8 + 1;
  iVar8 = DAT_0297e064 * 0x234;
  *pcVar4 = '\0';
  return &DAT_029801ac + iVar8;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f7fb0; label: FUN_004f7fb0
 */

void FUN_004f7fb0(int param_1)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  
  iVar7 = 0;
  bVar4 = false;
  if (*(char *)(param_1 + 0x578) != '\0') {
    FUN_004f7df0();
    return;
  }
  DAT_0088ab4c = *(uint *)(param_1 + 0x520);
  uVar5 = 0;
  if (*(char *)((*(int *)(param_1 + 0x514) - 1U & DAT_0088ab4c) + *(int *)(param_1 + 0x50c)) != '\0'
     ) {
    do {
      cVar2 = *(char *)(*(int *)(param_1 + 0x520) + *(int *)(param_1 + 0x50c));
      pcVar6 = *(char **)(param_1 + 0x580);
      if ((pcVar6 != (char *)0x0) && (iVar7 == 0)) {
        cVar3 = *pcVar6;
        while (cVar3 != '\0') {
          if (cVar3 == cVar2) {
            if (uVar5 == 0) {
              **(char **)(param_1 + 0x510) = cVar2;
              *(int *)(param_1 + 0x520) = *(int *)(param_1 + 0x520) + 1;
              uVar5 = 1;
            }
            goto LAB_004f80e5;
          }
          pcVar1 = pcVar6 + 1;
          pcVar6 = pcVar6 + 1;
          cVar3 = *pcVar1;
        }
      }
      pcVar6 = *(char **)(param_1 + 0x57c);
      if ((pcVar6 != (char *)0x0) && (iVar7 == 0)) {
        cVar3 = *pcVar6;
        while (cVar3 != '\0') {
          if (cVar3 == cVar2) goto LAB_004f8070;
          pcVar1 = pcVar6 + 1;
          pcVar6 = pcVar6 + 1;
          cVar3 = *pcVar1;
        }
      }
      if ((((cVar2 == '\t') || (cVar2 == ' ')) || (cVar2 == ',')) && (iVar7 == 0)) {
LAB_004f8070:
        if (uVar5 != 0) break;
      }
      else if (cVar2 == '\"') {
        iVar7 = 1 - iVar7;
        bVar4 = true;
      }
      else {
        *(char *)((*(int *)(param_1 + 0x518) - 1U & uVar5) + *(int *)(param_1 + 0x510)) = cVar2;
        uVar5 = uVar5 + 1;
      }
      *(int *)(param_1 + 0x520) = *(int *)(param_1 + 0x520) + 1;
      if ((((bVar4) && (iVar7 == 0)) && (uVar5 == 0)) ||
         (*(char *)((*(int *)(param_1 + 0x514) - 1U & *(uint *)(param_1 + 0x520)) +
                   *(int *)(param_1 + 0x50c)) == '\0')) break;
    } while( true );
  }
LAB_004f80e5:
  *(undefined1 *)((*(int *)(param_1 + 0x518) - 1U & uVar5) + *(int *)(param_1 + 0x510)) = 0;
  return;
}


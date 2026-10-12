/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f7df0; label: FUN_004f7df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004f7df0(int param_1)

{
  char *pcVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  char *pcVar7;
  uint uVar8;
  short sVar6;
  
  iVar4 = param_1;
  DAT_0088ab4c = *(uint *)(param_1 + 0x520);
  psVar2 = *(short **)(param_1 + 0x510);
  iVar3 = *(int *)(param_1 + 0x50c);
  uVar8 = 0;
  sVar6 = *(short *)(iVar3 + ((*(int *)(param_1 + 0x514) >> 1) - 1U & DAT_0088ab4c) * 2);
  param_1 = 0;
  do {
    if (sVar6 == 0) {
      psVar2[(*(int *)(iVar4 + 0x518) >> 1) - 1U & uVar8] = 0;
      return uVar8;
    }
    pcVar7 = *(char **)(iVar4 + 0x580);
    sVar6 = *(short *)(iVar3 + *(int *)(iVar4 + 0x520) * 2);
    if ((pcVar7 != (char *)0x0) && (param_1 == 0)) {
      cVar5 = *pcVar7;
      while (cVar5 != '\0') {
        if (cVar5 == (char)sVar6) {
          if (uVar8 == 0) {
            uVar8 = 1;
            *psVar2 = sVar6;
            *(int *)(iVar4 + 0x520) = *(int *)(iVar4 + 0x520) + 1;
          }
          psVar2[(*(int *)(iVar4 + 0x518) >> 1) - 1U & uVar8] = 0;
          return uVar8;
        }
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
        cVar5 = *pcVar1;
      }
    }
    pcVar7 = *(char **)(iVar4 + 0x57c);
    if ((pcVar7 != (char *)0x0) && (param_1 == 0)) {
      cVar5 = *pcVar7;
      while (cVar5 != '\0') {
        if (cVar5 == (char)sVar6) {
          sVar6 = 0x20;
          break;
        }
        pcVar1 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
        cVar5 = *pcVar1;
      }
    }
    cVar5 = (char)sVar6;
    if ((((cVar5 == '\t') || (cVar5 == ' ')) || (cVar5 == ',')) && (param_1 == 0)) {
      if (uVar8 != 0) {
        psVar2[(*(int *)(iVar4 + 0x518) >> 1) - 1U & uVar8] = 0;
        return uVar8;
      }
    }
    else if (sVar6 == 0x22) {
      if ((param_1 == 0) || (*(short *)(iVar3 + *(int *)(iVar4 + 0x520) * 2 + 2) != 0x22)) {
        param_1 = 1 - param_1;
      }
      else {
        psVar2[(*(int *)(iVar4 + 0x518) >> 1) - 1U & uVar8] = 0x22;
        uVar8 = uVar8 + 1;
        *(int *)(iVar4 + 0x520) = *(int *)(iVar4 + 0x520) + 1;
      }
    }
    else {
      psVar2[(*(int *)(iVar4 + 0x518) >> 1) - 1U & uVar8] = sVar6;
      uVar8 = uVar8 + 1;
    }
    *(int *)(iVar4 + 0x520) = *(int *)(iVar4 + 0x520) + 1;
    sVar6 = *(short *)(iVar3 + ((*(int *)(iVar4 + 0x514) >> 1) - 1U & *(uint *)(iVar4 + 0x520)) * 2)
    ;
  } while( true );
}


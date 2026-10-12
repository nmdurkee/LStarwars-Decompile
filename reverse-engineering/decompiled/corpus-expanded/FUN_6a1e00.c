/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1e00; label: FUN_006a1e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

void FUN_006a1e00(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  undefined1 auStack_114 [88];
  undefined4 uStack_bc;
  undefined1 auStack_b8 [4];
  int aiStack_b4 [4];
  undefined1 auStack_a4 [4];
  undefined1 auStack_a0 [4];
  int aiStack_9c [33];
  undefined4 uStack_18;
  int local_c;
  
  uStack_18 = 0x6a1e12;
  iVar1 = *(int *)(unaff_ESI + 0x14);
  aiStack_9c[1] = 0x6a1e24;
  iVar2 = iVar1 * -4;
  *(undefined4 *)(unaff_ESI + 0x1c) = 1;
  if (0x40 < iVar1 - *(int *)(unaff_ESI + 0x30)) {
    iVar6 = 0;
    local_c = 0;
    if (0 < *(int *)(*(int *)(unaff_ESI + 4) + 4)) {
      do {
        iVar4 = 0;
        if (0 < *(int *)(unaff_ESI + 0x14)) {
          do {
            iVar3 = iVar4 + 1;
            aiStack_9c[(iVar4 - iVar1) + 2] =
                 *(int *)(*(int *)(*(int *)(unaff_ESI + 8) + iVar6) + -4 +
                         (*(int *)(unaff_ESI + 0x14) - iVar4) * 4);
            iVar4 = iVar3;
          } while (iVar3 < *(int *)(unaff_ESI + 0x14));
        }
        iVar4 = *(int *)(unaff_ESI + 0x14);
        iVar3 = *(int *)(unaff_ESI + 0x30);
        aiStack_9c[1 - iVar1] = 0x20;
        aiStack_9c[-iVar1] = iVar4 - iVar3;
        *(int **)(auStack_a0 + iVar2) = aiStack_9c + 2;
        *(int **)(auStack_a4 + iVar2) = aiStack_9c + (2 - iVar1);
        aiStack_b4[3 - iVar1] = 0x6a1e7f;
        FUN_006b1580();
        iVar4 = *(int *)(unaff_ESI + 0x14) - *(int *)(unaff_ESI + 0x30);
        aiStack_b4[3 - iVar1] = *(int *)(unaff_ESI + 0x30);
        aiStack_b4[2 - iVar1] = (int)(aiStack_9c + (iVar4 - iVar1) + 2);
        aiStack_b4[1 - iVar1] = 0x20;
        aiStack_b4[-iVar1] = (int)(auStack_114 + iVar4 * 4 + iVar2);
        *(int **)(auStack_b8 + iVar2) = aiStack_9c + 2;
        (&uStack_bc)[-iVar1] = 0x6a1e9e;
        FUN_006b1890();
        iVar4 = 0;
        if (0 < *(int *)(unaff_ESI + 0x14)) {
          do {
            iVar3 = iVar4 - iVar1;
            iVar5 = *(int *)(unaff_ESI + 0x14) - iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(*(int *)(*(int *)(unaff_ESI + 8) + iVar6) + -4 + iVar5 * 4) =
                 aiStack_9c[iVar3 + 2];
          } while (iVar4 < *(int *)(unaff_ESI + 0x14));
        }
        local_c = local_c + 1;
        iVar6 = iVar6 + 4;
      } while (local_c < *(int *)(*(int *)(unaff_ESI + 4) + 4));
    }
  }
  return;
}


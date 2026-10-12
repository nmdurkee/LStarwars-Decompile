/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580790; label: FUN_00580790
 */

void FUN_00580790(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  
  iVar5 = 0;
  if (0 < *(int *)(PTR_PTR_008040bc + 4)) {
    psVar6 = (short *)(*(int *)PTR_PTR_008040bc + 0x2a);
    do {
      psVar6[0x1f] = 0;
      psVar6[0x20] = 0;
      psVar6[0x21] = 0;
      psVar6[0x22] = 0;
      psVar6[0x23] = 0;
      psVar6[0x24] = 0;
      psVar6[0x25] = 0;
      psVar6[0x26] = 0;
      psVar6[0x27] = 0;
      psVar6[0x28] = 0;
      psVar6[0x29] = 0;
      psVar6[0x2a] = 0;
      psVar6[0x2b] = 0;
      psVar6[0x2c] = 0;
      psVar6[0x2d] = 0;
      psVar6[0x2e] = 0;
      psVar6[0x2f] = 0;
      psVar6[0x30] = 0;
      psVar6[0x31] = 0;
      psVar6[0x32] = 0;
      psVar6[0x33] = 0;
      psVar6[0x34] = 0;
      psVar6[0x35] = 0;
      psVar6[0x36] = 0;
      sVar1 = psVar6[-1];
      if (sVar1 != -1) {
        puVar2 = (undefined4 *)(sVar1 * 0x10 + *(int *)(param_1 + 0x2ac0));
        *(undefined4 *)(psVar6 + 0x1f) = *puVar2;
        *(undefined4 *)(psVar6 + 0x21) = puVar2[1];
        *(undefined4 *)(psVar6 + 0x23) = puVar2[2];
        if (*psVar6 != -1) {
          puVar2 = (undefined4 *)(*psVar6 * 0x10 + *(int *)(param_1 + 0x2ac0));
          *(undefined4 *)(psVar6 + 0x25) = *puVar2;
          *(undefined4 *)(psVar6 + 0x27) = puVar2[1];
          *(undefined4 *)(psVar6 + 0x29) = puVar2[2];
        }
        iVar3 = FUN_0057a390((int)sVar1);
        if (iVar3 == -1) {
          *(undefined4 *)(psVar6 + 0x2b) = *(undefined4 *)(psVar6 + 0x1f);
          *(undefined4 *)(psVar6 + 0x2d) = *(undefined4 *)(psVar6 + 0x21);
          *(undefined4 *)(psVar6 + 0x2f) = *(undefined4 *)(psVar6 + 0x23);
          uVar4 = *(undefined4 *)(psVar6 + 0x29);
          *(undefined4 *)(psVar6 + 0x31) = *(undefined4 *)(psVar6 + 0x25);
          *(undefined4 *)(psVar6 + 0x33) = *(undefined4 *)(psVar6 + 0x27);
        }
        else {
          puVar2 = (undefined4 *)(iVar3 * 0x10 + *(int *)(param_1 + 0x2ac0));
          *(undefined4 *)(psVar6 + 0x2b) = *puVar2;
          *(undefined4 *)(psVar6 + 0x2d) = puVar2[1];
          *(undefined4 *)(psVar6 + 0x2f) = puVar2[2];
          if ((*psVar6 == -1) || (iVar3 = FUN_0057a390((int)*psVar6), iVar3 == -1))
          goto LAB_005808a8;
          puVar2 = (undefined4 *)(iVar3 * 0x10 + *(int *)(param_1 + 0x2ac0));
          *(undefined4 *)(psVar6 + 0x31) = *puVar2;
          *(undefined4 *)(psVar6 + 0x33) = puVar2[1];
          uVar4 = puVar2[2];
        }
        *(undefined4 *)(psVar6 + 0x35) = uVar4;
      }
LAB_005808a8:
      if (psVar6[1] == -1) {
        uVar4 = 0;
        psVar6[0x37] = 0;
        psVar6[0x38] = 0;
        psVar6[0x39] = 0;
        psVar6[0x3a] = 0;
      }
      else {
        puVar2 = (undefined4 *)(psVar6[1] * 0x10 + *(int *)(param_1 + 0x2ac0));
        *(undefined4 *)(psVar6 + 0x37) = *puVar2;
        *(undefined4 *)(psVar6 + 0x39) = puVar2[1];
        uVar4 = puVar2[2];
      }
      *(undefined4 *)(psVar6 + 0x3b) = uVar4;
      iVar5 = iVar5 + 1;
      psVar6 = psVar6 + 0x52;
    } while (iVar5 < *(int *)(PTR_PTR_008040bc + 4));
  }
  return;
}


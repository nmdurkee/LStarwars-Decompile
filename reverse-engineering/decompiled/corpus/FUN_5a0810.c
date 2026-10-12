/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0810; label: FUN_005a0810
 */

undefined4 * FUN_005a0810(int param_1,int *param_2,float param_3,float param_4,int param_5)

{
  short *psVar1;
  float fVar2;
  undefined4 *puVar3;
  int *piVar4;
  ushort *puVar5;
  int iVar6;
  float10 fVar7;
  
  if (param_1 == 0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xc) == 0) {
    return (undefined4 *)0x0;
  }
  if (param_2 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar6 = FUN_005cfac0(param_2);
  if (iVar6 == 0) {
    return (undefined4 *)0x0;
  }
  *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + '\x01';
  psVar1 = (short *)(*(int *)(param_1 + 0x10) + 2);
  *psVar1 = *psVar1 + 1;
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0xc);
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = *puVar3;
  if (param_5 == 0) {
    *puVar3 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    *puVar3 = 0;
    piVar4 = *(int **)(param_1 + 0x18);
    if (piVar4 != (int *)0x0) {
      iVar6 = *piVar4;
      while (iVar6 != 0) {
        piVar4 = (int *)*piVar4;
        iVar6 = *piVar4;
      }
      *piVar4 = (int)puVar3;
      goto LAB_005a0895;
    }
  }
  *(undefined4 **)(param_1 + 0x18) = puVar3;
LAB_005a0895:
  puVar5 = *(ushort **)(param_1 + 0x10);
  puVar3[9] = (((int)puVar3 - *(int *)(puVar5 + 4)) / 0x28) * (uint)*puVar5 + *(int *)(puVar5 + 8);
  piVar4 = puVar3 + 1;
  *piVar4 = *param_2;
  puVar3[2] = param_2[1];
  puVar3[3] = param_2[2];
  iVar6 = FUN_005d0420(piVar4);
  puVar3[4] = iVar6;
  if (iVar6 != 0) {
    puVar3[5] = *(undefined4 *)(*(int *)(*piVar4 + 0x54) + (uint)*(ushort *)(iVar6 + 0x5c) * 4);
    fVar7 = (float10)FUN_005e9650(piVar4);
    fVar2 = (float)fVar7;
    if (0.0 < fVar2) {
      if (param_4 <= fVar2) {
        if (1.0 <= param_4) {
          puVar3[7] = param_4;
        }
        else {
          puVar3[7] = 0x3f800000;
        }
      }
      else {
        puVar3[7] = fVar2;
      }
      if ((param_3 <= fVar2) && (fVar2 = param_3, param_3 < 1.0)) {
        puVar3[6] = 0x3f800000;
        *(char *)(param_1 + 9) = *(char *)(param_1 + 9) + '\x01';
        return puVar3;
      }
      puVar3[6] = fVar2;
      *(char *)(param_1 + 9) = *(char *)(param_1 + 9) + '\x01';
      return puVar3;
    }
    iVar6 = FUN_005cfa50(piVar4);
    if (iVar6 != 0) {
      FUN_005a0450(iVar6);
    }
  }
  return puVar3;
}


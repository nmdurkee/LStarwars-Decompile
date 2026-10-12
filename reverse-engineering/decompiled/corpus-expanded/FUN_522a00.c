/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522a00; label: FUN_00522a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00522a00(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_14;
  undefined1 local_c [12];
  
  iVar6 = 0;
  local_14 = 3.4028235e+38;
  if (in_EAX != 0) {
    for (iVar5 = FUN_004f1440(in_EAX + 0x18); iVar5 != 0; iVar5 = FUN_004f1460(in_EAX + 0x18,iVar5))
    {
      fVar7 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x10,iVar5 + 0x18,local_c);
      fVar1 = (float)fVar7;
      if (fVar1 < local_14) {
        fVar4 = *(float *)(DAT_009238e4 + 0x14) - *(float *)(iVar5 + 0x1c);
        if (0.2 <= *(float *)(iVar5 + 0x2c)) {
          fVar2 = *(float *)(iVar5 + 0x2c);
        }
        else {
          fVar2 = 0.2;
        }
        if (*(float *)(iVar5 + 0x28) <= -0.2) {
          fVar3 = *(float *)(iVar5 + 0x28);
        }
        else {
          fVar3 = -0.2;
        }
        if (((fVar4 <= fVar2) && (fVar3 < fVar4 != (fVar3 == fVar4))) &&
           ((param_1 == 0 || (fVar1 < *(float *)(iVar5 + 0x24) * *(float *)(iVar5 + 0x24))))) {
          iVar6 = iVar5;
          local_14 = fVar1;
        }
      }
    }
    return iVar6;
  }
  return 0;
}


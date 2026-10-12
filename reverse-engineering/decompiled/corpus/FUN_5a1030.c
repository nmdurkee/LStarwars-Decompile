/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a1030; label: FUN_005a1030
 */

undefined4 FUN_005a1030(float param_1,float param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (int)param_1;
  if (param_1 != 0.0) {
    if (param_3 != 0) {
      FUN_005a0670(param_1);
    }
    *(ushort *)((int)param_1 + 10) = *(ushort *)((int)param_1 + 10) & 0xfffd;
    if (param_2 < 0.0) {
      if ((param_2 < 0.0) && (*(int *)((int)param_1 + 0xc) == 0)) {
        return 1;
      }
    }
    else if (*(int *)((int)param_1 + 0xc) == 2) {
      return 1;
    }
    for (puVar2 = *(undefined4 **)((int)param_1 + 0x18); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[4] != 0) {
        *(uint *)(puVar2[4] + 0x50) = *(uint *)(puVar2[4] + 0x50) | 1;
        *(uint *)(puVar2[4] + 0x50) = *(uint *)(puVar2[4] + 0x50) & 0xfffffffb;
        if ((float)puVar2[6] <= (float)puVar2[7]) {
          param_1 = 1.0;
        }
        else {
          param_1 = -1.0;
        }
        fVar4 = param_1 * *(float *)(puVar2[4] + 0x4c);
        if ((float)puVar2[6] * param_1 <= fVar4) {
          if ((float)puVar2[7] * param_1 < fVar4) {
            uVar1 = puVar2[7];
            goto LAB_005a110b;
          }
        }
        else {
          uVar1 = puVar2[6];
LAB_005a110b:
          *(undefined4 *)(puVar2[4] + 0x4c) = uVar1;
        }
        iVar3 = puVar2[4];
        if (*(float *)(iVar3 + 0x54) == 0.0) {
          *(float *)(iVar3 + 0x40) = param_1 * param_2;
        }
        else {
          *(float *)(iVar3 + 0x40) = *(float *)(iVar3 + 0x54) * param_2 * param_1;
        }
      }
    }
    if (((*(byte *)(iVar5 + 10) & 4) == 0) && (*(int *)(iVar5 + 0x14) != 0)) {
      FUN_004f1310(*(int *)(iVar5 + 0x14),iVar5);
      *(ushort *)(iVar5 + 10) = *(ushort *)(iVar5 + 10) | 4;
    }
  }
  return 1;
}


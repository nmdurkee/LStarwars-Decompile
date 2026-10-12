/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66f8f0; label: FUN_0066f8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066f8f0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar4 = FUN_005be3b0(*(undefined4 *)(DAT_0292186c + 0x28),*(undefined4 *)(DAT_0292186c + 0x30));
  iVar3 = DAT_0292186c;
  *(float *)(DAT_0292186c + 0x48) = (float)iVar4;
  fVar1 = *(float *)(iVar3 + 0x30);
  fVar2 = *(float *)(iVar3 + 0x28);
  fVar5 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1 * fVar1);
  iVar4 = FUN_005be3b0(-*(float *)(DAT_0292186c + 0x2c),(float)fVar5);
  iVar3 = DAT_0292186c;
  *(float *)(DAT_0292186c + 0x44) = (float)iVar4;
  fVar5 = (float10)FUN_005c0240(*(float *)(iVar3 + 0x30) * *(float *)(iVar3 + 0x30) +
                                *(float *)(iVar3 + 0x28) * *(float *)(iVar3 + 0x28) +
                                *(float *)(iVar3 + 0x2c) * *(float *)(iVar3 + 0x2c));
  *(float *)(DAT_0292186c + 0x4c) = (float)fVar5;
  return;
}


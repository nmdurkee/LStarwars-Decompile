/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53e410; label: FUN_0053e410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053e410(short *param_1,undefined2 *param_2)

{
  float fVar1;
  float fVar2;
  short sVar3;
  undefined2 uVar4;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar5;
  
  fVar1 = *unaff_ESI - *unaff_EDI;
  fVar2 = unaff_ESI[2] - unaff_EDI[2];
  fVar5 = (float10)FUN_005c0240(fVar1 * fVar1 + fVar2 * fVar2);
  sVar3 = FUN_005be2d0(unaff_ESI[1] - unaff_EDI[1],(float)fVar5);
  *param_1 = -sVar3;
  uVar4 = FUN_005be2d0(fVar1,fVar2);
  *param_2 = uVar4;
  return;
}


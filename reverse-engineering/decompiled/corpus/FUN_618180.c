/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x618180; label: FUN_00618180
 */

void FUN_00618180(float param_1,float param_2,float param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *unaff_ESI;
  float *unaff_EDI;
  
  if (param_2 != 0.0) {
    if (param_1 == 360.0) {
      param_1 = 0.0;
    }
    FUN_005b7cc0(param_1 / 60.0);
    iVar4 = FUN_006e6b90();
    fVar1 = param_1 / 60.0 - (float)iVar4;
    fVar3 = param_3 * (1.0 - param_2);
    fVar2 = (1.0 - fVar1 * param_2) * param_3;
    fVar1 = param_3 * (1.0 - (1.0 - fVar1) * param_2);
    switch(iVar4) {
    case 0:
      *param_4 = param_3;
      *unaff_EDI = fVar1;
      *unaff_ESI = fVar3;
      return;
    case 1:
      *param_4 = fVar2;
      *unaff_EDI = param_3;
      *unaff_ESI = fVar3;
      return;
    case 2:
      *param_4 = fVar3;
      *unaff_EDI = param_3;
      *unaff_ESI = fVar1;
      return;
    case 3:
      *param_4 = fVar3;
      *unaff_EDI = fVar2;
      *unaff_ESI = param_3;
      return;
    case 4:
      *param_4 = fVar1;
      *unaff_EDI = fVar3;
      *unaff_ESI = param_3;
      return;
    case 5:
      *param_4 = param_3;
      *unaff_EDI = fVar3;
      *unaff_ESI = fVar2;
      return;
    default:
      return;
    }
  }
  *param_4 = param_3;
  *unaff_EDI = param_3;
  *unaff_ESI = param_3;
  return;
}


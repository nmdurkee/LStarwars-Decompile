/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6ca2f0; label: FUN_006ca2f0
 */

int FUN_006ca2f0(float *param_1)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int *piVar4;
  float local_20;
  float local_1c;
  float local_18;
  
  *param_1 = 0.0;
  piVar4 = (int *)*in_ECX;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  iVar3 = 0;
  param_1[3] = 1.0;
  if (piVar4 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    do {
      iVar2 = FUN_006c8760(8,DAT_02973ab8,&local_20,0);
      if (iVar2 != 0) {
        iVar3 = iVar3 + 1;
        *param_1 = *param_1 + local_20;
        param_1[1] = param_1[1] + local_1c;
        param_1[2] = param_1[2] + local_18;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    if (0 < iVar3) {
      fVar1 = 1.0 / (float)iVar3;
      *param_1 = fVar1 * *param_1;
      param_1[1] = param_1[1] * fVar1;
      param_1[2] = fVar1 * param_1[2];
      return iVar3;
    }
  }
  return iVar3;
}


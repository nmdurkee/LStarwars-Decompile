/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a35f0; label: FUN_005a35f0
 */

void FUN_005a35f0(float *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *unaff_ESI;
  float *unaff_EDI;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if (param_4 != 0) {
    FUN_005b3830(local_18,param_2,0xbf800000);
  }
  if (param_5 != 0) {
    FUN_005b3830(local_c,param_3,0xbf800000);
  }
  FUN_005b37d0(&local_30);
  FUN_005b37d0(&local_24);
  fVar2 = 1.0 - param_6;
  fVar4 = fVar2 * fVar2 * fVar2;
  fVar1 = param_6 * param_6 * param_6;
  fVar3 = fVar2 * param_6 * 3.0 * fVar2;
  fVar2 = fVar2 * param_6 * 3.0 * param_6;
  *param_1 = fVar4 * *unaff_EDI + fVar3 * local_30 + fVar2 * local_24 + fVar1 * *unaff_ESI;
  param_1[1] = unaff_ESI[1] * fVar1 + local_20 * fVar2 + local_2c * fVar3 + unaff_EDI[1] * fVar4;
  param_1[2] = fVar1 * unaff_ESI[2] + fVar2 * local_1c + unaff_EDI[2] * fVar4 + local_28 * fVar3;
  return;
}


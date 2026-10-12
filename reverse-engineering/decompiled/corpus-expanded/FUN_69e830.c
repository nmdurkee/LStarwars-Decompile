/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69e830; label: FUN_0069e830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069e830(void *param_1,size_t param_2,int param_3,code *param_4,int param_5,int param_6)

{
  int *piVar1;
  int in_EAX;
  void *_Dst;
  void *pvVar2;
  int iVar3;
  int *unaff_ESI;
  
  pvVar2 = param_1;
  if ((in_EAX == 0) || (param_4 == (code *)0x0)) {
    param_1 = (void *)0xffffffff;
  }
  else {
    param_1 = (void *)(*param_4)();
  }
  _memset(unaff_ESI,0,0x2d0);
  unaff_ESI[0xb0] = param_3;
  *unaff_ESI = in_EAX;
  unaff_ESI[0xb1] = (int)param_4;
  piVar1 = unaff_ESI + 6;
  unaff_ESI[0xb2] = param_5;
  unaff_ESI[0xb3] = param_6;
  FUN_0069f400(piVar1);
  if (pvVar2 != (void *)0x0) {
    _Dst = (void *)FUN_0069f4a0(piVar1,param_2);
    _memcpy(_Dst,pvVar2,param_2);
    FUN_0069f520(piVar1,param_2);
  }
  if (param_1 != (void *)0xffffffff) {
    unaff_ESI[1] = 1;
  }
  unaff_ESI[0xd] = 1;
  pvVar2 = _calloc(1,0x20);
  unaff_ESI[0x12] = (int)pvVar2;
  pvVar2 = _calloc(unaff_ESI[0xd],0x10);
  unaff_ESI[0x13] = (int)pvVar2;
  FUN_0069ee00(unaff_ESI + 0x1e,0xffffffff);
  iVar3 = FUN_0069b9c0(unaff_ESI[0x12],unaff_ESI[0x13],unaff_ESI + 0x17);
  if (iVar3 < 0) {
    *unaff_ESI = 0;
    FUN_0069c3c0();
    return iVar3;
  }
  unaff_ESI[0x16] = 1;
  return iVar3;
}


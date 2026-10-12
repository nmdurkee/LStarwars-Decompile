/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573be0; label: FUN_00573be0
 */

void FUN_00573be0(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  short sVar1;
  int *in_EAX;
  int iVar2;
  short *psVar3;
  undefined2 *unaff_EDI;
  
  if ((*in_EAX < param_1) && (iVar2 = FUN_00630680(), iVar2 == 0)) {
    unaff_EDI[*in_EAX * 2] = (short)param_2;
    unaff_EDI[*in_EAX * 2 + 1] = (undefined2)param_3;
    *in_EAX = *in_EAX + 1;
    unaff_EDI[*in_EAX * 2] = 0xffff;
  }
  if ((((param_4 != (undefined4 *)0x0) && (unaff_EDI != &DAT_00951258)) && (param_3 != 0)) &&
     (psVar3 = (short *)*param_4, psVar3 != (short *)0x0)) {
    while (param_2 != *psVar3) {
      psVar3 = (short *)param_4[2];
      param_4 = param_4 + 2;
      if (psVar3 == (short *)0x0) {
        return;
      }
    }
    sVar1 = *(short *)param_4[1];
    if (((sVar1 != -1) && (*in_EAX < param_1)) && (iVar2 = FUN_00630680(), iVar2 == 0)) {
      unaff_EDI[*in_EAX * 2] = sVar1;
      unaff_EDI[*in_EAX * 2 + 1] = (undefined2)param_3;
      *in_EAX = *in_EAX + 1;
      unaff_EDI[*in_EAX * 2] = 0xffff;
    }
  }
  return;
}


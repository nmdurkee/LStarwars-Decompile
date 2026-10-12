/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703db0; label: FUN_00703db0
 */

DName * FUN_00703db0(DName *param_1,DName *param_2)

{
  int iVar1;
  DName *in_ECX;
  DName *this;
  
  DName::DName(param_1,in_ECX);
  iVar1 = DName::isEmpty(param_1);
  if (iVar1 == 0) {
    FUN_00703bb1(param_2);
  }
  else {
    DName::operator=(this,param_2);
  }
  return param_1;
}


/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703db0; label: FUN_00703db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


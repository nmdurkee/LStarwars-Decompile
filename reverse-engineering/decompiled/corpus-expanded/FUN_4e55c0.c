/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e55c0; label: FUN_004e55c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e55c0(void)

{
  int iVar1;
  float local_c [3];
  
  iVar1 = FUN_0054fa60();
  local_c[0] = (float)iVar1 * 1.5259022e-05 * 4.0 + 32.5;
  local_c[1] = -5.5;
  iVar1 = FUN_0054fa60();
  local_c[2] = (float)iVar1 * 1.5259022e-05 * 4.0 + 12.5;
  FUN_00547d70("Dianoga_Groan",local_c);
  return;
}


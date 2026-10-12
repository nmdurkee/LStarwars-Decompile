/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b2f80; label: FUN_005b2f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b2f80(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  uVar1 = in_EAX[1];
  uVar2 = in_EAX[2];
  uVar3 = in_EAX[3];
  *in_ECX = *in_EAX;
  in_ECX[1] = uVar1;
  in_ECX[2] = uVar2;
  in_ECX[3] = uVar3;
  return;
}


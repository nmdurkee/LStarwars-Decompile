/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x470010; label: FUN_00470010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00470010(void)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  *in_ECX = *in_EAX;
  in_ECX[1] = in_EAX[1];
  in_ECX[2] = in_EAX[2];
  in_ECX[3] = in_EAX[3];
  return;
}


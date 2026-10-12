/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c9260; label: FUN_004c9260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c9260(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  DAT_0088054c = in_EAX;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(char *)(in_ECX + 0x68) = (char)in_EAX;
  _DAT_00880568 = 0;
  DAT_00880558 = 0;
  return;
}


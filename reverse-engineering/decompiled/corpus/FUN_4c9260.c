/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c9260; label: FUN_004c9260
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


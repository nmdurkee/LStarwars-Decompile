/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746db0; label: FUN_00746db0
 */

void FUN_00746db0(undefined4 param_1,int param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x8a0) = 0;
  *(undefined4 *)(in_ECX + 0x8b0) = 0;
  *(undefined1 *)(in_ECX + 0x8b4) = 0;
  *(undefined4 *)(in_ECX + 0x8c4) = 0;
  *(undefined1 *)(in_ECX + 0x8c8) = 0;
  *(undefined4 *)(in_ECX + 0x8d8) = 0;
  *(undefined1 *)(in_ECX + 0x8dc) = 0;
  *(undefined4 *)(in_ECX + 0x8ec) = 0;
  *(undefined1 *)(in_ECX + 0x8f0) = 0;
  *(undefined4 *)(in_ECX + 0x900) = 0;
  *(undefined1 *)(in_ECX + 0x904) = 0;
  *(undefined4 *)(in_ECX + 0x914) = 0;
  *(undefined1 *)(in_ECX + 0x918) = 0;
  *(undefined4 *)(in_ECX + 0x928) = 0;
  *(undefined1 *)(in_ECX + 0x92c) = 0;
  *(undefined4 *)(in_ECX + 0x93c) = 0;
  FUN_00740f50(param_1,0x3000);
  FUN_00740f50(param_1,0x4000);
  FUN_00748460(param_1,0x100);
  *(undefined4 *)(in_ECX + 0x99c) = 0;
  FUN_0074ad30();
  *(int *)(in_ECX + 0x978) = param_2;
  *(undefined4 *)(in_ECX + 0x4b0) = 0;
  *(undefined4 *)(in_ECX + 0x89c) = 0;
  *(undefined4 *)(in_ECX + 0x940) = 0;
  *(undefined1 *)(in_ECX + 0x964) = 1;
  *(undefined1 *)(in_ECX + 0x965) = 0;
  *(undefined1 *)(in_ECX + 0x966) = 0;
  *(undefined4 *)(in_ECX + 0x974) = 4;
  *(undefined4 *)(in_ECX + 0x980) = 8;
  *(undefined4 *)(in_ECX + 0x984) = 2;
  *(undefined1 *)(in_ECX + 0x970) = 0;
  if (param_2 != 1) {
    *(undefined1 *)(in_ECX + 0x967) = 1;
    *(undefined1 *)(in_ECX + 0x968) = 1;
    *(undefined1 *)(in_ECX + 0x969) = 1;
    *(char **)(in_ECX + 0x96c) = ": register(c%d)";
    *(char **)(in_ECX + 0x988) = "_centroid";
    return;
  }
  *(undefined1 *)(in_ECX + 0x967) = 0;
  *(undefined1 *)(in_ECX + 0x968) = 0;
  *(undefined1 *)(in_ECX + 0x969) = 0;
  *(char **)(in_ECX + 0x96c) = ": c%d";
  *(undefined1 **)(in_ECX + 0x988) = &DAT_007516c0;
  return;
}


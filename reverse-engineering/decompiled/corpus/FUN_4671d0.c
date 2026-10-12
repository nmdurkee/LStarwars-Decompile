/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x4671d0; label: FUN_004671d0
 */

void FUN_004671d0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x68) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x10);
  *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_EAX + 0x14);
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(in_EAX + 0x18);
  FUN_005a0c20(*(undefined4 *)(in_EAX + 0x28),(undefined4 *)(in_EAX + 0x1c),in_EAX + 0x68);
  return;
}


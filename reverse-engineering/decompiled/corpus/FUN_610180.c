/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x610180; label: FUN_00610180
 */

void FUN_00610180(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x90) != 0) {
    FID_conflict__wprintf("mHostList\n");
  }
  if (*(int *)(in_ECX + 0x9c) != 0) {
    FID_conflict__wprintf("mPeerList\n");
  }
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x48) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x4c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x50) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x54) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x58) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x5c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x60) = 0xffffffff;
  *(undefined4 *)(in_ECX + 100) = 0xffffffff;
  return;
}


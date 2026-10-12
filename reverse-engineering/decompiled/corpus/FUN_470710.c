/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x470710; label: FUN_00470710
 */

void FUN_00470710(void)

{
  int unaff_ESI;
  
  *(undefined1 *)(unaff_ESI + 0x7b5) = 0x2f;
  *(undefined2 *)(unaff_ESI + 0x7aa) = 0x68;
  if (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + 0x1a0) == 0) {
    *(undefined2 *)(unaff_ESI + 0x7aa) = 5;
  }
  FUN_0054a910(0,0x3dcccccd,0,0);
  *(undefined4 *)(unaff_ESI + 0x77c) = 0;
  *(undefined4 *)(unaff_ESI + 0x784) = 0x3f400000;
  *(undefined4 *)(unaff_ESI + 0x748) = *(undefined4 *)(unaff_ESI + 0x8c);
  *(undefined4 *)(unaff_ESI + 0x74c) = *(undefined4 *)(unaff_ESI + 0x90);
  *(undefined4 *)(unaff_ESI + 0x750) = *(undefined4 *)(unaff_ESI + 0x94);
  *(undefined1 *)(unaff_ESI + 0x7b3) = 0;
  FUN_00576960(0x28b);
  return;
}


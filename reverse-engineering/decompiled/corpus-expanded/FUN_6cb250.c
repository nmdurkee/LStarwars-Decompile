/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cb250; label: FUN_006cb250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cb250(void)

{
  undefined4 *in_ECX;
  
  FUN_00633500();
  *in_ECX = &PTR_FUN_0076feec;
  in_ECX[0x24f] = 0;
  in_ECX[0x250] = 0;
  in_ECX[0x251] = 0;
  in_ECX[0x428] = 0x3f800000;
  in_ECX[0x427] = &PTR_FUN_0076f6e0;
  in_ECX[0x429] = 1;
  in_ECX[0x42b] = 0;
  in_ECX[0xaa] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0x3f800000;
  in_ECX[0x3be] = 0x80808080;
  in_ECX[0x405] = 0x80808080;
  in_ECX[0xd] = 0x3f19999a;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 1;
  in_ECX[0xc] = 1;
  in_ECX[0xe] = 1;
  in_ECX[0x3ba] = 0;
  in_ECX[0x3bb] = 0;
  in_ECX[0x3bc] = 0x280;
  in_ECX[0x3bd] = 0x1c0;
  in_ECX[0x3bf] = 0x40000000;
  in_ECX[0x400] = 0;
  in_ECX[0x401] = 0;
  in_ECX[0x402] = 0x280;
  in_ECX[0x403] = 0x1c0;
  in_ECX[0x404] = 0x80000000;
  FUN_006bc430(0x1000,&DAT_0076fee0);
  FUN_006bc430(0x4000,"D-Down");
  FUN_006bc430(0x8000,"D-Left");
  FUN_006bc430(0x2000,"D-Right");
  FUN_006bc430(0x10,"Triangle");
  FUN_006bc430(0x40,"Cross");
  FUN_006bc430(0x80,"Square");
  FUN_006bc430(0x20,"Circle");
  FUN_006bc430(4,&DAT_0076feb0);
  FUN_006bc430(1,&DAT_0076feac);
  FUN_006bc430(8,&DAT_0076fea8);
  FUN_006bc430(2,&DAT_0076fea4);
  FUN_006bc430(0x200,&DAT_0076fea0);
  FUN_006bc430(0x400,&DAT_0076fea8);
  FUN_006bc430(0x800,"START");
  FUN_006bc430(0x100,"SELECT");
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_b88322fe7ca6c602bc72773b9244a05ea8c75e29ff1db88ba7165308671a45a1
 * Entry: 0x703b4f; label: DName::operator+=
 */

/* Library Function - Single Match
    public: class DName & __thiscall DName::operator+=(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __thiscall DName::operator+=(DName *this,DName *param_1)

{
  int iVar1;
  DNameNode *this_00;
  DName *this_01;
  
  iVar1 = isEmpty(param_1);
  if (iVar1 == 0) {
    iVar1 = isEmpty(this);
    if (iVar1 == 0) {
      this_00 = DNameNode::clone(*(DNameNode **)this);
      *(DNameNode **)this = this_00;
      if (this_00 == (DNameNode *)0x0) {
        *(uint *)(this + 4) = *(uint *)(this + 4) & 0xfffffff3 | 3;
      }
      else {
        DNameNode::operator+=(this_00,*(DNameNode **)param_1);
      }
    }
    else {
      operator=(this_01,param_1);
    }
  }
  else {
    operator+=(this,(*(int *)(param_1 + 4) << 0x1c) >> 0x1c);
  }
  return this;
}


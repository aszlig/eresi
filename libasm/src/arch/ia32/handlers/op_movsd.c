/*
** $Id: op_movsd.c,v 1.1 2007-01-26 14:18:38 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_movsd" opcode="0xa5"/>
*/

int op_movsd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
    new->len += 1;
    new->ptr_instr = opcode;
    if (asm_proc_opsize(proc))
      new->instr = ASM_MOVSW;
    else
      new->instr = ASM_MOVSD;

    new->op1.type = ASM_OTYPE_YDEST;
    new->op2.type = ASM_OTYPE_XSRC;

    new->op1.prefix = ASM_PREFIX_ES;
    new->op1.regset = ASM_REGSET_R32;
    new->op1.content = ASM_OP_BASE | ASM_OP_REFERENCE;
    new->op1.base_reg = ASM_REG_EDI;
    new->op1.len = 0;
  
  new->op2.content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op2.len = 0;
  new->op2.prefix = ASM_PREFIX_DS;
  new->op2.regset = ASM_REGSET_R32;
  new->op2.base_reg = ASM_REG_ESI;



  return (new->len);
}